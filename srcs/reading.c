/*
** reading.c for  in /home/wasta-geek/rendu/UNIX/NETWORK_TEK2/PSU_2015_myftp
** 
** Made by Wasta-Geek
** Login   <ducate_c@epitech.net>
** 
** Started on  Tue May  3 13:37:30 2016 Wasta-Geek
** Last update Fri May 13 21:27:08 2016 Wasta-Geek
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	"errors.h"

static int	count_word(char *str)
{
  int		counter;
  int		result;

  counter = 0;
  result = 1;
  while (str[counter] != '\0')
    {
      if (str[counter] == ' ' && str[counter + 1] != ' '
	  && str[counter + 1] != '\0')
	result++;
      counter++;
    }
  return (result);
}

char	**my_str_to_wordtab(char *str)
{
  int	counter_word;
  int	nbr_word;
  char	**wordtab;
  int	counter_size;
  int	counter_str;

  counter_word = -1;
  counter_str = 0;
  nbr_word = count_word(str);
  if ((wordtab = malloc(sizeof(char*) * (1 + nbr_word))) == NULL)
    return (NULL);
  while (++counter_word < nbr_word)
    {
      counter_size = 0;
      while (str[counter_str + counter_size] != '\0'
	     && str[counter_str + counter_size] != ' '
	     && str[counter_str + counter_size] != '\n')
	counter_size++;
      wordtab[counter_word] = strndup(str + counter_str, counter_size);
      wordtab[counter_word][counter_size] = '\0';
      counter_str += counter_size;
      while (str[++counter_str] == ' ');
    }
  wordtab[counter_word] = NULL;
  return (wordtab);
}

void	free_wordtab(char **wordtab)
{
  int	counter;

  counter = 0;
  if (wordtab == NULL)
    return ;
  while (wordtab[counter] != NULL)
    free(wordtab[counter++]);
  free(wordtab);
}

char			get_datas(char **line, char ***wordtab, FILE *stream_client)
{
  long unsigned int	len;

  len = 0;
  if (getline(line, &len, stream_client) == -1)
    return (print_error("Error while reading on the client"));
  if ((*line)[strlen(*line) - 2] == '\r')
    (*line)[strlen(*line) - 2] = '\0';
  *wordtab = my_str_to_wordtab(*line);
  return (0);
}
