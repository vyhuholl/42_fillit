/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 20:45:01 by sghezn            #+#    #+#             */
/*   Updated: 2019/04/28 17:40:46 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

/*
** A structure that represents a square map of tetriminos of a given size.
*/

typedef struct	s_map
{
	char	**arr;
	int		size;
}				t_map;

/*
** A structure that represents a tetrimino fitting into x_len * y_len rectangle,
** marked with a given letter.
*/

typedef struct	s_piece
{
	char	letter;
	char	**arr;
	int		x_len;
	int		y_len;
}				t_piece;

# define CHECK(input, i, letter) ((input[i]) == ('#') ? (letter) : (input[i]));

t_list			*ft_read(int fd);
int				ft_get_x_start(char *input);
int				ft_get_x_end(char *input);
int				ft_get_y_start(char *input);
int				ft_get_y_end(char *input);
char			**ft_get_arr(char *input, int x_len, int y_len, char letter);
int				ft_touches(t_piece *piece, char letter, int x, int y);
int				ft_is_connected(t_piece *piece, char letter);
t_piece			*ft_construct_piece(char *input, char letter);
t_piece 		*ft_is_ok(char *input, char letter);
int				ft_is_map_ok(t_map *map, t_list *input);
t_map			*ft_create_map(int size);
int				ft_can_place(t_map *map, t_piece *piece, int i, int j);
void			ft_place(t_map *map, t_piece *piece, int x, int y);
size_t			ft_min_size(t_list *list);
t_map			*ft_solve(t_list *input);
void			ft_free_piece(t_piece *piece);
t_list			*ft_free_list(t_list *list);
void			ft_free_map(t_map *map);
void			ft_print(t_map *map);
void			ft_place_empty(t_map *map, t_piece *piece, int x, int y);

#endif
