/*
** writing.c for  in /home/wasta-geek/rendu/UNIX/NETWORK_TEK2/PSU_2015_myftp
** 
** Made by Wasta-Geek
** Login   <ducate_c@epitech.net>
** 
** Started on  Mon May  2 15:42:57 2016 Wasta-Geek
** Last update Wed May  4 13:56:07 2016 Wasta-Geek
*/

#include	<string.h>
#include	<unistd.h>
#include	"errors.h"

char	my_putstr(char *str, int fd)
{
  if (write(fd, str, strlen(str)) < (int)strlen(str))
    return (print_error("Error while writing to the client"));
  return (0);
}
