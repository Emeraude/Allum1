/*
** my_str.c for  in /home/broggi_t/lib
** 
** Made by broggi_t
** Login   <broggi_t@epitech.net>
** 
** Started on  Mon Jan 13 01:40:14 2014 broggi_t
** Last update Sun Feb 16 00:18:27 2014 
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_str.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

int		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
  return (0);
}

void		my_puterr(char *str)
{
  if (str == NULL)
    return;
  write(2, str, my_strlen(str));
}

void		my_putnbr(int nbr)
{
  if (nbr < 0)
    {
      nbr *= -1;
      my_putchar('-');
    }
  if (nbr / 10 > 0)
    my_putnbr(nbr / 10);
  my_putchar(nbr % 10 + 48);
}

int		my_strlen(char *str)
{
  int		i;

  if (str == NULL)
    return (-1);
  i = -1;
  while (str[++i]);
  return (i);
}
