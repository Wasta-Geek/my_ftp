/*
** path_commands.h for  in /home/wasta-geek/rendu/UNIX/NETWORK_TEK2/PSU_2015_myftp
** 
** Made by Wasta-Geek
** Login   <ducate_c@epitech.net>
** 
** Started on  Fri May 13 23:34:59 2016 Wasta-Geek
** Last update Sat May 14 20:22:34 2016 Wasta-Geek
*/

#ifndef		PATH_COMMANDS_H_
# define	PATH_COMMANDS_H_

# define	_GNU_SOURCE
#include	"commands.h"

void		pwd_function(char *, char **, int, t_serv*);
void		cwd_function(char *, char **, int, t_serv*);
void		cdup_function(char *, char **, int, t_serv*);

#endif		/* path_commands.h */
