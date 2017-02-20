/*
** common_command_functions.c for  in /home/wasta-geek/rendu/UNIX/NETWORK_TEK2/PSU_2015_myftp
** 
** Made by Wasta-Geek
** Login   <ducate_c@epitech.net>
** 
** Started on  Sat May 14 21:43:47 2016 Wasta-Geek
** Last update Sun May 15 17:38:16 2016 Wasta-Geek
*/

#include	<errno.h>
#include	<arpa/inet.h>
#include	<netdb.h>
#include	<sys/socket.h>
#include	<unistd.h>
#include	"errors.h"
#include	"files_functions.h"
#include	"writing.h"

char			connect_me(t_serv *infos, int fd_client)
{
  struct sockaddr_in	addr;
  socklen_t		len;
  int			tmp;
  struct protoent	*proto_s;

  tmp = infos->fd_data;
  len = 0;
  if (infos->mode == PASSIVE)
    {
      if ((infos->fd_data = accept(tmp, (struct sockaddr*)&addr, &len))  == -1)
	my_putstr("426 An error occured while accepting\r\n", fd_client);
      close(tmp);
      return (0);
    }
  if ((proto_s = getprotobyname("TCP")) == NULL)
    return (print_error("An error occured while getting prototype\r\n"));
  if ((infos->fd_data = socket(AF_INET, SOCK_STREAM, proto_s->p_proto)) == -1)
    return (print_error("An error occured while creating socket\r\n"));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(infos->port);
  addr.sin_addr.s_addr = inet_addr(infos->ip);
  if (connect(infos->fd_data, (struct sockaddr*)&addr, sizeof(addr)) == -1)
    my_putstr("426 An error occured while connecting\r\n", fd_client);
  return (0);
}

void	write_in_file(int fd_file, t_serv *infos)
{
  int	ret;
  int	counter;
  char	tmp_line[1028];

  while ((ret = read(infos->fd_data, &tmp_line, 1024)) > 0)
    {
      counter = -1;
      while (++counter < ret)
	if (!(tmp_line[counter] == '\r' && tmp_line[counter + 1] == '\n'))
	  write(fd_file, &tmp_line[counter], 1);
    }
}
