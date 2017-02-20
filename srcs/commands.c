/*
** commands.c for  in /home/wasta-geek/rendu/UNIX/NETWORK_TEK2/PSU_2015_myftp
** 
** Made by Wasta-Geek
** Login   <ducate_c@epitech.net>
** 
** Started on  Tue May  3 12:48:17 2016 Wasta-Geek
** Last update Sun May 15 18:56:05 2016 Wasta-Geek
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<unistd.h>
#include	"commands.h"
#include	"errors.h"
#include	"reading.h"
#include	"file_commands.h"
#include	"mode_commands.h"
#include	"path_commands.h"
#include	"tab_ptr.h"
#include	"writing.h"

t_tab		f_tab[] = {
  { "NOOP", &noop_function },
  { "HELP", &help_function },
  { "QUIT", &quit_function },
  { "CWD", &cwd_function },
  { "PWD", &pwd_function },
  { "CDUP", &cdup_function },
  { "PASV", &pasv_function },
  { "PORT", &port_function },
  { "LIST", &list_function },
  { "RETR", &retr_function },
  { "STOR", &stor_function },
  { "DELE", &dele_function },
  { "END", NULL },
};

static	void	execute_command(char *line, char **wordtab, int fd_client,
				t_serv *infos)
{
  int		counter;

  counter = 0;
  while (strcmp(f_tab[counter].name, "END") != 0
	 && strcasecmp(f_tab[counter].name, wordtab[0]) != 0)
    counter++;
  /* if (strcasecmp(wordtab[0], "user") == 0 || strcasecmp(wordtab[1], "pass") == 0) */
  /*   my_putstr("230 Already logged in\r\n", fd_client); */
  /* else  */if (strcmp(f_tab[counter].name, "END") == 0)
    my_putstr("500 Unknown command\r\n", fd_client);
  else
    f_tab[counter].ptr(line, wordtab, fd_client, infos);
}

void	quit_function(char *line, char **wordtab, int fd_client, t_serv *info)
{
  (void)line;
  (void)wordtab;
  info->must_quit = 1;
  my_putstr("221 Thanks you for coming, see you soon !\r\n", fd_client);
}

void	help_function(char *line, char **wordtab, int fd_client, t_serv *info)
{
  (void)line;
  (void)info;
  if (strcasecmp(wordtab[0], "HELP") == 0)
    my_putstr("214 All basic ftp's command\r\n", fd_client);
}

void	noop_function(char *line, char **wordtab, int fd_client, t_serv *info)
{
  (void)line;
  (void)wordtab;
  (void)fd_client;
  (void)info;
  my_putstr("200 NOOP OKAY !\r\n", fd_client);
  return ;
}

void		manage_command(int fd_client, FILE *stream_client)
{
  char		*line;
  char		**wordtab;
  t_serv	info;

  info.must_quit = 0;
  info.mode = NO_MODE;
  info.fd_data = -1;
  while (info.must_quit == 0)
    {
      line = NULL;
      wordtab = NULL;
      get_datas(&line, &wordtab, stream_client);
      printf("%s\n", line);
      execute_command(line, wordtab, fd_client, &info);
      my_free(line);
      free_wordtab(wordtab);
    }
}
