/*
** my_strcmp.c for  in /home/broggi_t/rush
** 
** Made by broggi_t
** Login   <broggi_t@epitech.net>
** 
** Started on  Sat Dec 14 16:33:30 2013 broggi_t
** Last update Thu Feb 13 09:58:11 2014 
*/

#include <stdlib.h>
#include "my_str.h"

int		my_strcmp(char *s1, char *s2)
{
  unsigned int	i;

  if (s1 == NULL || s2 == NULL)
    return (0);
  i = 0;
  while (s1[i] && s1[i] == s2[i])
    i++;
  return ((!s1[i] && !s2[i]) ? (1) : (0));
}
