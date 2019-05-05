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

/* a function which creates a new empty map of a given size */

t_map	*ft_create_map(size_t size)
{
	t_map	*map;
	size_t	i;
	size_t	j;

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

/* a function which places a piece marked with letter L at the map */
/* (with piece's upper-left corner located at (x, y)) */

void	ft_place(t_map *map, t_piece *piece, int x, int y, char L)
{
	int	i;
	int	j;

	j = 0;
	while (j < piece->x_len)
	{
		i = 0;
		while (i < piece->y_len)
		{
			if (piece->arr[i][j] == '#')
				map->arr[y + i][x + j] = L;
			i++;
		}
		j++;
	}
}

/* auxillary function which returns a minimum possible size for the new map */
/* -- minimum n such as n >= len^2, where n is a number of tetriminos */

size_t	ft_min_size(t_list *list)
{
	size_t	len;
	size_t	res;
	t_list	*ptr;

	len = 0;
	ptr = *list;
	while (ptr)
	{
		ptr = ptr->next;
		len++;
	}
	res = 2;
	while (res * res < len)
		res++;
	return (res);
}

/* a function which returns a solution */

t_map	*ft_solve(t_list *input)
{
	t_map	*map;
	size_t	size;

	size = ft_min_size(input);
	map = ft_create_map(size);
	while (!ft_is_map_ok(map, input))
	{
		size += 1;
		ft_free_map(map);
		map = ft_create_map(size);
	}
	return (map);
}
