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

typedef struct	s_map
{
	char	**arr;
	size_t	size;
}				t_map;

int		ft_is_char_ok(char **tetrimino, int i, int j)
int		ft_is_ok(char **tetrimino);
t_list	*ft_read(const int fd);
t_map	*ft_create_map(int size)
t_map	*ft_solve(t_list *input);
void	ft_free_map(t_map *map);
void	ft_print(t_map *map);

#endif
