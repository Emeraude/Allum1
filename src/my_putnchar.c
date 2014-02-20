/*
** my_putnchar.c for  in /home/broggi_t/projets/allum1/src
** 
** Made by 
** Login   <broggi_t@epitech.net>
** 
** Started on  Tue Feb  4 14:38:01 2014 
** Last update Tue Feb  4 14:39:59 2014 
*/

#include "my_str.h"

void		my_putnchar(char c, int nb)
{
  int		i;

  i = -1;
  while (++i < nb)
    my_putchar(c);
}
