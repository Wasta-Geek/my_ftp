/*
** mode_commands.c for  in /home/wasta-geek/rendu/UNIX/NETWORK_TEK2/PSU_2015_myftp
** 
** Made by Wasta-Geek
** Login   <ducate_c@epitech.net>
** 
** Started on  Sat May 14 00:29:21 2016 Wasta-Geek
** Last update Sun May 15 17:26:01 2016 Wasta-Geek
*/

#include	<arpa/inet.h>
#include	<netdb.h>
#include	<string.h>
#include	<unistd.h>
#include	"commands.h"
#include	"sockets.h"
#include	"writing.h"

static void	print_passiv(struct sockaddr_in *addr, int fd_client)
{
  int		port;
  char		*ip;
  int		counter;

  counter = 0;
  port = ntohs(addr->sin_port);
  ip = inet_ntoa(addr->sin_addr);
  my_putstr("227 Passiv mode activated (", fd_client);
  while (ip[counter] != '\0')
    {
      if (ip[counter] == '.')
	write(fd_client, ",", 1);
      else
	write(fd_client, &(ip[counter]), 1);
      counter++;
    }
  dprintf(fd_client, ",%d,%d).\r\n", port / 256, port % 256);
}

static int	get_nbr(char *line, int pos)
{
  int		counter;
  int		result;
  int		mult;

  counter = pos;
  result = 0;
  mult = 1;
  while (line[counter] != ',')
    {
      result += (line[counter] - '0') * mult;
      mult *= 10;
      counter--;
    }
  return (result);
}

static int	get_port(char *line)
{
  int		port1;
  int		port2;
  int		counter;
  int		counter_comma;

  counter_comma = 0;
  counter = 0;
  while (counter_comma < 4 && line[counter] != '\0')
    if (line[counter++] == ',')
      counter_comma++;
  counter_comma = 0;
  while (line[counter + counter_comma + 1] != ',' && line[counter] != '\0')
    counter_comma++;
  port1 = get_nbr(line, counter + counter_comma);
  port2 = get_nbr(line, strlen(line) - 1);
  return (port1 * 256 + port2);
}

void	port_function(char *line, char **wordtab, int fd_client, t_serv *infos)
{
  int	counter;
  int	counter_comma;

  (void)line;
  (void)wordtab;
  counter = 0;
  counter_comma = 0;
  infos->port = get_port(wordtab[1]);
  while (wordtab[1][counter] != '\0' && counter_comma < 4)
    {
      if (wordtab[1][counter] == ',')
	{
	  counter_comma++;
	  wordtab[1][counter] = '.';
	}
      counter++;
    }
  wordtab[1][counter - 1] = '\0';
  infos->ip = strdup(wordtab[1]);
  infos->mode = ACTIVE;
  my_putstr("200 Active mode activated !\r\n", fd_client);
  //  my_putstr("500 Illegal PORT command.\r\n");
}

void			pasv_function(char *line, char **wordtab, int fd_client, t_serv *infos)
{
  struct sockaddr_in	addr;
  socklen_t		addr_len;

  (void)line;
  (void)wordtab;
  addr_len = sizeof(addr);
  infos->fd_data = initialize_sockets(0, fd_client);
  getsockname(infos->fd_data, (struct sockaddr*)&addr, &addr_len);
  if (infos->fd_data != -1)
    {
      infos->mode = PASSIVE;
      print_passiv(&addr, fd_client);
    }
}
