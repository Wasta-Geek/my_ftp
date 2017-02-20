/*
** reading.h for  in /home/wasta-geek/rendu/UNIX/NETWORK_TEK2/PSU_2015_myftp
** 
** Made by Wasta-Geek
** Login   <ducate_c@epitech.net>
** 
** Started on  Tue May  3 17:44:43 2016 Wasta-Geek
** Last update Fri May 13 20:16:41 2016 Wasta-Geek
*/

#ifndef		READING_H_
# define	READING_H_

char		**my_str_to_wordtab(char *);
void		free_wordtab(char **);
char		get_datas(char **, char ***, FILE*);

#endif		/* reading.h */
