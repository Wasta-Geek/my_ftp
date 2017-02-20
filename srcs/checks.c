/*
** checks.c for  in /home/wasta-geek/rendu/UNIX/NETWORK_TEK2/PSU_2015_myftp
** 
** Made by Wasta-Geek
** Login   <ducate_c@epitech.net>
** 
** Started on  Mon May  2 13:11:30 2016 Wasta-Geek
** Last update Mon May  2 14:38:17 2016 Wasta-Geek
*/

#include	<ctype.h>
#include	"errors.h"

int	check_args(int ac, char **av)
{
  int	counter;

  if (ac != 3)
    return (print_error("Not enough parameter\nUsage : ./server port path"));
  counter = 0;
  while (av[1][counter] != '\0')
    {
      if (isdigit(av[1][counter]) == 0)
	return (print_error("Port must be a number and must be non-negative"));
      counter++;
    }
  return (0);
}
