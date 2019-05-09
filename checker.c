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

int		ft_conn(char *input)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i < 20)
	{
		if (input[i] == '#')
		{
			if (i + 1 < 20 && input[i + 1] == '#')
				n++;
			if (i - 1 >= 0 && input[i - 1] == '#')
				n++;
			if (i + 5 < 20 && input[i + 5] == '#')
				n++;
			if (i - 5 >= 0 && input[i - 5] == '#')
				n++;
		}
		i++;
	}
	if (n == 6 || n == 8)
		return (1);
	return (0);
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
	piece->letter = letter;
	piece->x_len = x_end - x_start;
	piece->y_len = y_end - y_start;
	piece->arr = ft_get_arr(input, piece->x_len, piece->y_len, letter);
	return (piece);
}

/*
** A function which constructs a tetrimino
** marked with a given letter from input.
*/

t_piece	*ft_is_ok(char *input, char letter, int cnt)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (input[i] != '#' && input[i] != '.')
				return (NULL);
			if (input[i] == '#')
				count++;
		}
		else if (input[i] != '\n')
			return (NULL);
		i++;
	}
	if (cnt == 21 && input[20] != '\n')
		return (NULL);
	if (count != 4 || ft_conn(input) == 0)
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
	piece = (t_piece*)(input->content);
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
					ft_place_empty(map, piece, i, j);
			}
			i++;
		}
		j++;
	}
	return (0);
}
