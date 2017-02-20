/*
** errors.c for  in /home/wasta-geek/rendu/UNIX/NETWORK_TEK2/PSU_2015_myftp
** 
** Made by Wasta-Geek
** Login   <ducate_c@epitech.net>
** 
** Started on  Mon May  2 13:37:01 2016 Wasta-Geek
** Last update Fri May 13 11:46:11 2016 Wasta-Geek
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>

void	my_free(void *thing)
{
  if (thing != NULL)
    free(thing);
}

char	print_error(char *str)
{
  printf("%s\n", str);
  return (-1);
}

char	close_print_error(char *str, int fd)
{
  close(fd);
  printf("%s\n", str);
  return (-1);
}

char	free_print_error(char *str, char *to_free)
{
  my_free(to_free);
  printf("%s\n", str);
  return (-1);
}
