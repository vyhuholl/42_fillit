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

t_piece	*ft_construct_piece(char *input, char letter, int cnt)
{
	t_piece	*piece;
	char	**arr;
	int		i;

	if (!ft_is_ok(input, cnt))
		return (NULL);
	piece = (t_piece*)malloc(sizeof(t_piece) + 1);
	piece->x_len = ft_get_x_len(input);
	piece->y_len = ft_get_y_len(input);
	piece->letter = letter;
	arr = (char**)malloc(sizeof(char*) * (piece->y_len + 1));
	i = 0;
	while (i < piece->y_len)
	{
		arr[i] = (char*)malloc(sizeof(char) * (piece->x_len + 1));
		ft_strncpy(arr[i], input + ft_get_start(input, i), piece->x_len);
		i++;
	}
	piece->arr = arr;
	return (piece);
}

/*
** A function which constructs a tetrimino
** marked with a given letter from input.
*/

int		ft_is_ok(char *input, int cnt)
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
				return (0);
			if (input[i] == '#')
				count++;
		}
		else if (input[i] != '\n')
			return (0);
		i++;
	}
	if (cnt == 21 && input[20] != '\n')
		return (0);
	if (count != 4 || ft_conn(input) == 0)
		return (0);
	return (1);
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
