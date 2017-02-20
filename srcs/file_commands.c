/*
** file_commands.c for  in /home/wasta-geek/rendu/UNIX/NETWORK_TEK2/PSU_2015_myftp
** 
** Made by Wasta-Geek
** Login   <ducate_c@epitech.net>
** 
** Started on  Sat May 14 00:27:51 2016 Wasta-Geek
** Last update Sun May 15 19:54:23 2016 Wasta-Geek
*/

#include	"file_commands.h"
#include	<arpa/inet.h>
#include	<dirent.h>
#include	<fcntl.h>
#include	<stdio.h>
#include	<sys/types.h>
#include	<unistd.h>
#include	"errors.h"
#include	"files_functions.h"
#include	"tab_ptr.h"
#include	"writing.h"

void	dele_function(char *line, char **wordtab, int fd_client, t_serv *infos)
{
  (void)*line;
  (void)infos;
  if (access(wordtab[1], F_OK) != 0)
    my_putstr("550 File doesn't exist\r\n", fd_client);
  else if (wordtab[1] == NULL || wordtab[2] != NULL)
    my_putstr("501 Only one file can be remove\r\n", fd_client);
  else if (unlink(wordtab[1]) == 0)
    my_putstr("250 A file has been removed\r\n", fd_client);
  else
    my_putstr("550 Cannot remove directory\r\n", fd_client);
}

void	stor_function(char *line, char **wordtab, int fd_client, t_serv *infos)
{
  int	fd_file;

  (void)*line;
  (void)*wordtab;
  if (infos->mode == NO_MODE)
    my_putstr("425 No mode selected\r\n", fd_client);
  else
    {
      connect_me(infos, fd_client);
      if ((fd_file = open(wordtab[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR
			  | S_IRGRP | S_IWGRP | S_IROTH)) == -1)
	my_putstr("550 can't create file\r\n", fd_client);
      else
	{
	  my_putstr("150 Connexion is ready\r\n", fd_client);
	  write_in_file(fd_file, infos);
	  my_putstr("226 End of transmission\r\n", fd_client);
	  close(fd_file);
	}
      close(infos->fd_data);
    }
}

void	retr_function(char *line, char **wordtab, int fd_client, t_serv *infos)
{
  int	fd_file;
  char	l_read[1024];
  int	tmp;

  (void)*line;
  if (infos->mode == NO_MODE)
    my_putstr("425 No mode selected\r\n", fd_client);
  else
    {
      connect_me(infos, fd_client);
      if ((fd_file = open(wordtab[1], O_RDONLY)) == -1)
	my_putstr("550 This file doesn't exist\r\n", fd_client);
      else
	{
	  my_putstr("150 Connexion is ready\r\n", fd_client);
	  while ((tmp = read(fd_file, l_read, 1024)) > 0)
	    {
	      l_read[tmp] = '\0';
	      write(infos->fd_data, l_read, tmp);
	    }
	  my_putstr("226 End of transmission\r\n", fd_client);
	  close(fd_file);
	}
      close(infos->fd_data);
    }
}

void	list_function(char *line, char **wordtab, int fd_client, t_serv *infos)
{
  DIR	*dir;
  struct dirent	*s_dir;

  (void)*line;
  (void)*wordtab;
  if (infos->mode == NO_MODE)
    my_putstr("425 No mode selected\r\n", fd_client);
  else
    {
      connect_me(infos, fd_client);
      if ((dir = opendir(get_current_dir_name())) == NULL)
	my_putstr("450 Error while listing files\r\n", fd_client);
      else
	{
	  my_putstr("150 Here come the directory listing\r\n", fd_client);
	  while ((s_dir = readdir(dir)) != NULL)
	    {
	      my_putstr(s_dir->d_name, infos->fd_data);
	      my_putstr("\n", infos->fd_data);
	    }
	  my_putstr("226 End of transmission\r\n", fd_client);
	  closedir(dir);
	}
      close(infos->fd_data);
    }
}
