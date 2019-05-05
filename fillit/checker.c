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

/* a function which checks whether a piece is connected */

int		ft_is_connected(t_piece *piece, char L)
{
	int i;
	int	j;

	j = 0;
	while (j < piece->x_len)
	{
		i = 0;
		while (i < piece->y_len)
		{
			if (piece[i][j] == L)
				if (!ft_touches(piece, L, j, i))
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

/* a function which constructs a tetrimino marked with letter L from input */

t_piece	*ft_construct_piece(char *input, char L, int x_len, int y_len)
{
	t_piece	*piece;
	char	arr[y_len][x_len];

	piece = ft_memalloc(sizeof(t_piece));
	piece->x_len = x_len;
	piece->y_len = y_len;
	piece->L = L;
	if (!ft_is_connected(piece, L))
		return (NULL);
	return (piece);
}

/* a function which returns a tetrimino marked with letter L if input is valid, NULL otherwise */

t_piece	*ft_is_ok(char *input, char L)
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
	x_len = ft_get_x_len(input);
	y_len = ft_get_y_len(input);
	return (ft_construct_piece(input, L, x_len, y_len));
}

/* a function which places a piece at the map (with piece's upper-left corner located at (x, y)) */
/* if it is possible and returns 0 otherwise */

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
	ft_place(map, piece, x, y, piece->L);
	return (1);
}

/* a function which checks using recursive backtracking whether it is possible */
/* to fit a list of tetriminos into a map of a given size */

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
					ft_place(map, piece, x, y, '.');;
			}
			i++;
		}
		j++;
	}
	return (0);
}
