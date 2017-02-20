/*
** main.c for  in /home/wasta-geek/rendu/UNIX/NETWORK_TEK2/PSU_2015_myftp
** 
** Made by Wasta-Geek
** Login   <ducate_c@epitech.net>
** 
** Started on  Mon May  2 12:48:08 2016 Wasta-Geek
** Last update Sun May 15 16:07:16 2016 Wasta-Geek
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"check.h"
#include	"errors.h"
#include	"sockets.h"

int	main(int ac, char **av)
{
  int	port;
  int	fd;

  if (check_args(ac, av) == -1)
    return (1);
  port = atoi(av[1]);
  if (port > 65535)
    return (print_error("Post must be a positiv integer smaller than 65536"));
  if ((fd = initialize_sockets(port, -1)) == -1)
    return (1);
  manage_process(fd, av[2]);
  close(fd);
  return (0);
}
