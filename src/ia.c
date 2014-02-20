/*
** ia.c for  in /home/broggi_t/projets/allum1
** 
** Made by 
** Login   <broggi_t@epitech.net>
** 
** Started on  Tue Feb  4 14:42:17 2014 
** Last update Sun Feb 16 00:05:43 2014 
*/

#include "alum.h"

static int	biggest_line(unsigned char *rows, int size)
{
  int		i;
  int		highest;

  i = 0;
  highest = 0;
  while (i < size)
    {
      if (rows[i] > rows[highest])
	highest = i;
      ++i;
    }
  return (highest);
}

static int	nb_lines(unsigned char *rows, int size)
{
  int		i;
  int		lines;

  i = 0;
  lines = 0;
  while (i < size)
    {
      if (rows[i] > 0)
	++lines;
      ++i;
    }
  return (lines);
}

int		ia(unsigned char *rows, int size)
{
  int		removed;

  removed = rows[biggest_line(rows, size)];
  if (nb_lines(rows, size) <= 3)
    --removed;
  if (removed < 1)
    removed = 1;
  remove_alums(rows, biggest_line(rows, size) + 1, removed, size);
  return (SUCCESS);
}
