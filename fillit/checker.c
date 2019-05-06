/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 20:59:33 by sghezn            #+#    #+#             */
/*   Updated: 2019/04/27 20:59:34 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** A function which checks whether a block of a tetrimino
** at (x, y) position touches at least one other block.
*/

int		ft_touches(t_piece *piece, char letter, int x, int y)
{
	if (x > 0 && piece->arr[x - 1][y] == letter)
		return (1);
	if (y > 0 && piece->arr[x][y - 1] == letter)
		return (1);
	if (x < piece->x_len - 1 && piece->arr[x + 1][y] == letter)
		return (1);
	if (y < piece->y_len - 1 && piece->arr[x][y + 1] == L)
		return (1);
	return (0);
}

/*
** A function which checks whether a piece is connected.
*/

int		ft_is_connected(t_piece *piece, char letter)
{
	int i;
	int	j;

	j = 0;
	while (j < piece->x_len)
	{
		i = 0;
		while (i < piece->y_len)
		{
			if (piece[i][j] == letter)
				if (!ft_touches(piece, letter, j, i))
				{
					ft_free_piece(piece);
					return (NULL);
				}
			i++;
		}
		j++;
	}
	return (1);
}

/*
** A function which constructs a tetrimino
** marked with a given letter from input.
*/

t_piece	*ft_construct_piece(char *input, char letter)
{
	t_piece	*piece;
	int		x_start;
	int		x_end;
	int		y_start;
	int		y_end;

	x_start = ft_get_x_start(input);
	x_end = ft_get_x_end(input);
	y_start = ft_get_y_start(input);
	y_end = ft_get_y_end(input);
	piece = ft_memalloc(sizeof(t_piece));
	piece->L = L;
	piece->x_len = x_end - x_start;
	piece->y_len = y_end - y_start;
	piece->arr = ft_get_arr(input, piece->x_len, piece->y_len);
	if (!ft_is_connected(piece, letter))
		return (NULL);
	return (piece);
}

/*
** A function which returns a tetrimino marked with
** a given letter if input is valid, NULL otherwise.
*/

t_piece	*ft_is_ok(char *input, char letter)
{
	int	i;
	int	count;
	int	x_len;
	int	y_len;

	i = 0;
	count = 0;
	while (i < 21)
	{
		if (input[i] != '#' && input[i] != '.')
			if (!(input[i] == '\n' && (i % 4 == 0)))
				return (NULL);
		if (input[i] == '#')
			count++;
		i++;
	}
	if (count != 4)
		return (NULL);
	return (ft_construct_piece(input, letter));
}

/*
** A function which checks using recursive backtracking whether
** it is possible to fit a list of tetriminos into a map of a given size.
*/

int		ft_is_map_ok(t_map *map, t_list *input)
{
	t_piece	*piece;
	int		i;
	int		j;

	if (!input)
		return (1);
	j = 0;
	piece = (t_piece)(input->content);
	while (j < map->size - piece->y_len + 1)
	{
		i = 0;
		while (i < map->size - piece->x_len + 1)
		{
			if (ft_can_place(map, piece, i, j))
			{
				if (ft_is_map_ok(map, input->next))
					return (1);
				else
					ft_place_empty(map, piece, x, y);
			}
			i++;
		}
		j++;
	}
	return (0);
}
