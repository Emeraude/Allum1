/*
** main.c for  in /home/broggi_t/projets/alum1/src
** 
** Made by 
** Login   <broggi_t@epitech.net>
** 
** Started on  Mon Feb  3 12:59:12 2014 
** Last update Sun Feb 16 22:28:26 2014 
*/

#include <stdlib.h>
#include "my_str.h"
#include "alum.h"

static int	display_help(char *str)
{
  my_putstr("Usage: ");
  my_putstr(str);
  my_putstr(" [-r rows] [-m mod]\n\n");
  my_putstr("Options:\n");
  my_putstr("-h, --help\t\t\tDislay this help and exit\n");
  my_putstr("-m, --mode\t\t\tChange the mode (number of human players)\n");
  my_putstr("-r, --rows, -l, --lines\t\t");
  my_putstr("Change the number of lines (maximum is ");
  my_putnbr(MAX_ROWS);
  my_putstr(")\n");
  return (0);
}

static int	print_param_error(char *str)
{
  my_puterr("\033[31mInvalid value after ");
  my_puterr(str);
  my_puterr(" operator\033[0m\n");
  return (FAILURE);
}

static int	check_params(char **av, int *size, int *mode)
{
  int		i;

  i = 0;
  while (av[++i] != NULL)
    {
      if (my_strcmp(av[i], "-h") || my_strcmp(av[i], "--help"))
	return (FAILURE + display_help(av[0]));
      else if (my_strcmp(av[i], "-r") || my_strcmp(av[i], "--rows") ||
	       my_strcmp(av[i], "-l") || my_strcmp(av[i], "--lines"))
	{
	  if (av[i + 1] == NULL || my_getnbr(av[i + 1]) < 1 ||
	      my_getnbr(av[i + 1]) > MAX_ROWS)
	    return (print_param_error(av[i]) + display_help(av[0]));
	  *size = my_getnbr(av[++i]);
	}
      else if (my_strcmp(av[i], "-m") || my_strcmp(av[i], "--mode"))
	{
	  if (av[i + 1] == NULL || my_getnbr(av[i + 1]) < 0 ||
	      my_getnbr(av[i + 1]) > 2)
	    return (print_param_error(av[i]) + display_help(av[0]));
	  *mode = my_getnbr(av[++i]);
	}
    }
  return (SUCCESS);
}

int		main(int ac, char **av)
{
  int		size;
  int		mode;

  size = 4;
  mode = 1;
  if (ac > 1 && check_params(av, &size, &mode) == FAILURE)
    return (1);
  if (game(size, mode) == FAILURE)
    return (1);
  return (0);
}
