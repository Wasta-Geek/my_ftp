/*
** to_login.c for  in /home/wasta-geek/rendu/UNIX/NETWORK_TEK2/PSU_2015_myftp
** 
** Made by Wasta-Geek
** Login   <ducate_c@epitech.net>
** 
** Started on  Wed May  4 17:58:56 2016 Wasta-Geek
** Last update Sat May 14 21:41:06 2016 Wasta-Geek
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	"errors.h"
#include	"reading.h"
#include	"writing.h"

static void	manage_login(int fd_client, char *login, char **wtab)
{
  if (*login  == 1)
    my_putstr("530 You cannot change user\r\n", fd_client);
  else
    {
      if (strcmp(wtab[1], "Anonymous") == 0)
	*login = 1;
      else
	*login = 2;
      my_putstr("331 A password is required\r\n", fd_client);
    }
}

static void	manage_passwd(int fd_client, char *login, char *is_logged,
			      char **wtab)
{
  if (*login == 1 && wtab[1] == NULL)
    {
      *is_logged = 1;
      my_putstr("230 You're now log in !\r\n", fd_client);
    }
  else if (*login == 0)
    my_putstr("332 A login is needed\r\n", fd_client);
  else if (wtab[1] != NULL || *login == 2)
    {
      *login = 0;
      my_putstr("331 Wrong pass\r\n", fd_client);
    }
}

static void	free_ressources(char *line, char **wtab)
{
  free_wordtab(wtab);
  my_free(line);
}

void			loop_to_log_in(int fd_client, FILE *s_cli, char *is_logged)
{
  char			*line;
  char			**wt;
  char			login;

  login = 0;
  while (*is_logged == 0)
    {
      wt = NULL;
      line = NULL;
      if (get_datas(&line, &wt, s_cli) == -1 || strcasecmp(line, "quit") == 0)
	*is_logged = -1;
      else if (wt[1] != NULL && strcasecmp(wt[0], "user") == 0)
	manage_login(fd_client, &login, wt);
      else if (strcasecmp(wt[0], "pass") == 0)
	manage_passwd(fd_client, &login, is_logged, wt);
      else
	my_putstr("530 You're not identificated !\r\n", fd_client);
      free_ressources(line, wt);
    }
}
