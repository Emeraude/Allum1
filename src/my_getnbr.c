/*
** my_getnbr.c for my_getnbr in /home/broggi_t/tmp/Piscine-C-Jour_04
** 
** Made by broggi_t
** Login   <broggi_t@epitech.net>
** 
** Started on  Thu Oct  3 18:42:28 2013 broggi_t
** Last update Sun Jan  5 14:34:28 2014 broggi_t
*/

#include "my_str.h"

int		my_getnbr(char *str)
{
  int		i;
  int		number;
  int		neg;

  i = 0;
  number = 0;
  neg = 1;
  while (str[i] != '\0')
    {
      if (str[i] == '-')
	neg = - neg;
      else if (str[i] >= '0' && str[i] <= '9')
	{
	  if (number > (number * 10 + (str[i] - 48)))
	    return (0);
	  number = number * 10 + str[i] - 48;
	}
      else if (str[i] != '+')
	return (number * neg);
      i = i + 1;
    }
  return (number * neg);
}
