/*
** path_commands.c for  in /home/wasta-geek/rendu/UNIX/NETWORK_TEK2/PSU_2015_myftp
** 
** Made by Wasta-Geek
** Login   <ducate_c@epitech.net>
** 
** Started on  Fri May 13 23:24:19 2016 Wasta-Geek
** Last update Sat May 14 20:22:57 2016 Wasta-Geek
*/

#include	"path_commands.h"
#include	<unistd.h>
#include	"errors.h"
#include	"tab_ptr.h"
#include	"writing.h"

void	pwd_function(char *line, char **wordtab, int fd_client, t_serv *infos)
{
  char	*path;

  (void)line;
  (void)wordtab;
  (void)infos;
  path = NULL;
  path = get_current_dir_name();
  my_putstr("257 \"", fd_client);
  my_putstr(path, fd_client);
  my_putstr("\"\r\n", fd_client);
  my_free(path);
}

void	cdup_function(char *line, char **wordtab, int fd_client, t_serv *infos)
{
  (void)line;
  (void)infos;
  (void)wordtab;
  if (chdir("..") == -1)
    my_putstr("550 You cannot move there\r\n", fd_client);
  else
    my_putstr("200 You've move to parent's directory !\r\n", fd_client);
}

void	cwd_function(char *line, char **wordtab, int fd_client, t_serv *infos)
{

  (void)line;
  (void)infos;
  if (wordtab[1] == NULL)
    my_putstr("501 No path specified\r\n", fd_client);
  else if (chdir(wordtab[1]) == -1)
    my_putstr("550 This directory don't exist\r\n", fd_client);
  else
    my_putstr("250 You've change directory successfully !\r\n", fd_client);
}
