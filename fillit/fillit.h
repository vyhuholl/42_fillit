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

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

/* a structure that represents a square map of tetriminos of a given size*/

typedef struct	s_map
{
	char	**arr;
	size_t	size;
}				t_map;

/* a structure that represents a tetrimino fitting into x_len * y_len rectangle, */
/* marked with letter L*/

typedef struct	s_piece
{
	char	L;
	char	**place;
	int		x_len;
	int		y_len;
}				t_piece;

t_piece	*ft_construct_piece(char *input, char L);
t_piece	*ft_is_ok(char *input, char L);
t_list	*ft_read(int fd);
t_map	*ft_create_map(size_t size);
size_t	ft_min_size(t_list *list);
t_map	*ft_solve(t_list *input);
void	ft_free_piece(t_piece *piece);
void	ft_free_list(t_list *list);
void	ft_free_map(t_map *map);
void	ft_print(t_map *map);

#endif
