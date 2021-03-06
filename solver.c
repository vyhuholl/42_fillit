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

/*
** A function which creates a new empty map of a given size.
*/

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

/*
** A function which places a piece at the map
** (with piece's upper-left corner located at (x, y))
** if it is possible and returns 0 otherwise.
*/

int		ft_can_place(t_map *map, t_piece *piece, int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j < piece->x_len)
	{
		i = 0;
		while (i < piece->y_len)
		{
			if (piece->arr[i][j] == '#' && map->arr[y + i][x + j] != '.')
				return (0);
			i++;
		}
		j++;
	}
	ft_place(map, piece, x, y);
	return (1);
}

/*
** A function which places a piece marked with letter L at the map
** (with piece's upper-left corner located at (x, y)).
*/

void	ft_place(t_map *map, t_piece *piece, int x, int y)
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
				map->arr[y + i][x + j] = piece->letter;
			i++;
		}
		j++;
	}
}

/*
** Auxillary function which returns a minimum possible size for the new map
** -- minimum n such as n >= (len * 4)^2, where len is the number of tetriminos.
*/

int		ft_min_size(t_list *list)
{
	int		len;
	int		res;
	t_list	*ptr;

	len = 0;
	ptr = list;
	while (ptr)
	{
		ptr = ptr->next;
		len++;
	}
	len *= 4;
	res = 2;
	while (res * res < len)
		res++;
	return (res);
}

/*
** A function which returns a solution.
*/

t_map	*ft_solve(t_list *input)
{
	t_map	*map;
	int		size;

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
