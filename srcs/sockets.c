/*
** sockets.c for  in /home/wasta-geek/rendu/UNIX/NETWORK_TEK2/PSU_2015_myftp
** 
** Made by Wasta-Geek
** Login   <ducate_c@epitech.net>
** 
** Started on  Mon May  2 13:49:48 2016 Wasta-Geek
** Last update Sun May 15 16:07:36 2016 Wasta-Geek
*/

#include	<arpa/inet.h>
#include	<netdb.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<unistd.h>
#include	"commands.h"
#include	"errors.h"
#include	"writing.h"

static int	manage_sockets(int fd_client)
{
  FILE		*stream_client;
  char		is_logged;

  is_logged = 0;
  stream_client = fdopen(fd_client, "r");
  loop_to_log_in(fd_client, stream_client, &is_logged);
  if (is_logged == -1)
    my_putstr("221 Thanks you for coming, see you soon !\r\n", fd_client);
  else
    manage_command(fd_client, stream_client);
  close(fd_client);
  fclose(stream_client);
  return (0);
}

static int		get_same_ip(int fd)
{
  struct sockaddr_in	addr;
  socklen_t		addr_len;

  if (fd == -1)
    return (htons(INADDR_ANY));
  addr_len = sizeof(addr);
  getsockname(fd, (struct sockaddr*)&addr, &addr_len);
  return (addr.sin_addr.s_addr);
}
int	initialize_sockets(int port, int fd_in)
{
  struct protoent	*proto_struct;
  int			fd;
  struct sockaddr_in	s_server;

  if ((proto_struct = getprotobyname("TCP")) == NULL)
    return (print_error("Error while getting protocol number"));
  if ((fd = socket(AF_INET, SOCK_STREAM,  proto_struct->p_proto)) == -1)
    return (print_error("Error while creating socket"));
  s_server.sin_family = AF_INET;
  s_server.sin_port = htons(port);
  s_server.sin_addr.s_addr = get_same_ip(fd_in);
  if (bind(fd, (const struct sockaddr*)&s_server, sizeof(s_server)) == -1)
    return (close_print_error("Error while assigning a name to a socket", fd));
  if (listen(fd, 42) == -1)
    return (close_print_error("Error while listening", fd));
  return (fd);
}

int			manage_process(int fd, char *path)
{
  socklen_t		size_struct;
  struct sockaddr_in	s_client;
  int			pid;
  int			fd_client;

  if (chdir(path) == -1)
    return (print_error("Error while changing directory"));
  while (666)
    {
      size_struct = sizeof(struct sockaddr_in);
      if ((fd_client = accept(fd,
			      (struct sockaddr*)&s_client, &size_struct)) == -1)
	return (print_error("Error while accepting a connection"));
      pid = fork();
      if (pid == 0)
	{
	  if (my_putstr("220 Glad to see you !\r\n", fd_client) < 0)
	    return (-1);
	  close(fd);
	  manage_sockets(fd_client);
	  return (0);
	}
      close(fd_client);
    }
  return (0);
}
