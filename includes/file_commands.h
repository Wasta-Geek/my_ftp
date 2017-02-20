/*
** file_commands.h for  in /home/wasta-geek/rendu/UNIX/NETWORK_TEK2/PSU_2015_myftp
** 
** Made by Wasta-Geek
** Login   <ducate_c@epitech.net>
** 
** Started on  Sat May 14 00:34:18 2016 Wasta-Geek
** Last update Sat May 14 21:26:18 2016 Wasta-Geek
*/

#ifndef		FILE_COMMANDS_H_
# define	FILE_COMMANDS_H_

#define		_GNU_SOURCE
#include	"commands.h"

void		dele_function(char *, char **, int, t_serv *);
void		retr_function(char *, char **, int, t_serv *);
void		stor_function(char *, char **, int, t_serv *);
void		list_function(char *, char **, int, t_serv *);

#endif		/* file_commands.h */
