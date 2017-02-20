/*
** commands.h for  in /home/wasta-geek/rendu/UNIX/NETWORK_TEK2/PSU_2015_myftp
** 
** Made by Wasta-Geek
** Login   <ducate_c@epitech.net>
** 
** Started on  Tue May  3 13:43:14 2016 Wasta-Geek
** Last update Sun May 15 17:19:45 2016 Wasta-Geek
*/

#ifndef		COMMANDS_H_
# define	COMMANDS_H_

#include	<stdio.h>

enum	e_mode {NO_MODE, PASSIVE, ACTIVE};

typedef struct	s_serv
{
  char		must_quit;
  enum e_mode	mode;
  int		fd_data;
  char		*ip;
  int		port;
}		t_serv;

char		loop_to_log_in(int, FILE*, char *);
void		manage_command(int, FILE*);
void		noop_function(char *, char **, int, t_serv *);
void		help_function(char *, char **, int, t_serv *);
void		quit_function(char *, char **, int, t_serv *);

#endif		/* commands.h */
