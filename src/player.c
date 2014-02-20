/*
** player.c for  in /home/broggi_t/projets/allum1/src
** 
** Made by 
** Login   <broggi_t@epitech.net>
** 
** Started on  Tue Feb 11 00:49:52 2014 
** Last update Sat Feb 15 18:16:07 2014 
*/

#include <stdlib.h>
#include "my_str.h"
#include "get_next_line.h"
#include "alum.h"

int		user(unsigned char *rows, int size)
{
  char		*readed;
  int		line;
  int		alums;
  int		state;

  state = FAILURE;
  while (state != SUCCESS)
    {
      my_putstr("Selection of the line: ");
      if ((readed = get_next_line(0)) == NULL)
	return (FAILURE);
      line = my_getnbr(readed);
      my_putstr("Number of alumettes in line ");
      my_putstr(readed);
      my_putstr(": ");
      free(readed);
      if ((readed = get_next_line(0)) == NULL)
	return (FAILURE);
      alums = my_getnbr(readed);
      free(readed);
      state = remove_alums(rows, line, alums, size);
    }
  return (SUCCESS);
}
