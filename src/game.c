/*
** game.c for  in /home/broggi_t/projets/alum1/src
** 
** Made by 
** Login   <broggi_t@epitech.net>
** 
** Started on  Mon Feb  3 22:32:05 2014 
** Last update Sun Feb 16 22:30:24 2014 
*/

#include <stdlib.h>
#include "alum.h"
#include "my_str.h"

static unsigned char	*create_tab(int size)
{
  unsigned char		*ret;
  int			i;

  if ((ret = malloc(size * sizeof(char))) == NULL)
    return (NULL);
  i = 0;
  while (i < size)
    {
      ret[i] = 2 * i + 1;
      ++i;
    }
  return (ret);
}

int		nb_alum(unsigned char *rows, int size)
{
  int		nb;
  int		i;

  i = 0;
  nb = 0;
  while (i < size)
    {
      nb += rows[i];
      ++i;
    }
  return (nb);
}

int		remove_alums(unsigned char *rows, int line,
			     int alums, int size)
{
  if (line < 0 || line > size || alums < 0 ||
      rows[line - 1] < 1 || rows[line - 1] < alums)
    return (FAILURE);
  else
    rows[line - 1] -= alums;
  return (SUCCESS);
}

static int	display(unsigned char *rows, int size, int player, int mode)
{
  int		i;

  print_player(mode, player);
  i = -1;
  while (++i < size)
    {
      my_putnbr(i + 1);
      my_putnchar(' ', 1 + (i < 9));
      my_putchar('(');
      my_putnbr(rows[i]);
      my_putstr("):");
      my_putnchar(' ', (rows[i] % 10 == 0) + (rows[i] < 10) +
		  size + i - rows[i] + 5);
      my_putnchar('|', rows[i]);
      my_putchar('\n');
    }
  return (SUCCESS);
}

int		game(int size, int mode)
{
  unsigned char	*rows;
  int		winner;

  if ((rows = create_tab(size)) == NULL)
    return (FAILURE);
  winner = 0;
  while (winner == 0)
    {
      if (display(rows, size, 1, mode) == SUCCESS && mode == 0)
	ia(rows, size);
      else if (user(rows, size) == FAILURE)
	return (FAILURE);
      winner = (nb_alum(rows, size) < 1) * 2;
      if (winner == 0)
	{
	  if (display(rows, size, 2, mode) == SUCCESS && mode < 2)
	    ia(rows, size);
	  else if (user(rows, size) == FAILURE)
	    return (FAILURE);
	  winner = (nb_alum(rows, size) < 1);
	}
    }
  print_winner(mode, winner);
  free(rows);
  return (SUCCESS);
}
