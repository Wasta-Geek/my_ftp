/*
** tab_ptr.h for  in /home/wasta-geek/rendu/UNIX/NETWORK_TEK2/PSU_2015_myftp
** 
** Made by Wasta-Geek
** Login   <ducate_c@epitech.net>
** 
** Started on  Fri May 13 20:36:41 2016 Wasta-Geek
** Last update Fri May 13 23:36:09 2016 Wasta-Geek
*/

#ifndef		TAB_PTR_H_
# define	TAB_PTR_H_

#include	"commands.h"

typedef struct	s_tab
{
  char		*name;
  void		(*ptr)(char *, char **, int, t_serv *);
}		t_tab;

#endif		/* tab_ptr.h */
