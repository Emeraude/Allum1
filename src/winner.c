/*
** winner.c for  in /home/broggi_t/projets/allum1/src
** 
** Made by 
** Login   <broggi_t@epitech.net>
** 
** Started on  Sun Feb 16 01:22:53 2014 
** Last update Sun Feb 16 01:59:45 2014 
*/

#include "my_str.h"
#include "alum.h"

void		print_winner(int mode, int winner)
{
  my_putstr("Winner: ");
  my_putstr((winner == 1) ? "\033[34m" : "\033[31m");
  my_putstr("Player ");
  my_putnbr(winner);
  my_putstr(" (");
  if ((winner == 1 && mode == 0) || (winner == 2 && mode < 2))
    my_putstr("IA");
  else
    my_putstr("human");
  my_putstr(")\033[0m\n");
}

void		print_player(int mode, int player)
{
  static int	turn = 0;

  my_putstr("Turn ");
  my_putnbr(++turn);
  my_putstr((player == 1) ? "\033[34m" : "\033[31m");
  my_putstr(": Player ");
  my_putnbr(player);
  my_putstr(" (");
  if ((player == 1 && mode == 0) || (winner == 2 && mode < 2))
    my_putstr("IA");
  else
    my_putstr("human");
  my_putstr(")\033[0m\n");
}
