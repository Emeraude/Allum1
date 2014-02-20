/*
** alum.h for  in /home/broggi_t/projets/alum1/include
** 
** Made by 
** Login   <broggi_t@epitech.net>
** 
** Started on  Mon Feb  3 12:52:05 2014 
** Last update Sun Feb 16 02:32:14 2014 
*/

#ifndef ALUM_H_
# define ALUM_H_

# define SUCCESS	0
# define FAILURE	1

# define MAX_ROWS	42

int		remove_alums(unsigned char *rows, int lines,
			     int alums, int size);
int		game(int size, int mode);

void		print_winner(int mode, int winner);
void		print_player(int mode, int player);

int		ia(unsigned char *rows, int size);
int		user(unsigned char *rows, int size);

#endif /* !ALUM_H_ */
