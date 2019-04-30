/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 21:00:24 by sghezn            #+#    #+#             */
/*   Updated: 2019/04/27 21:00:26 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*ft_create_map(int size)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map*)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->arr = (char**)ft_memalloc(sizeof(char*) * size);
	i = 0;
	while (i < size)
	{
		map->arr[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			map->arr[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

int		ft_put_piece()

t_map	*ft_solve(t_list *input)
{
	
}
