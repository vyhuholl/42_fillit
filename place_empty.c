/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_empty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:58:29 by sghezn            #+#    #+#             */
/*   Updated: 2019/05/06 20:58:31 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** A function which "reverts" a placement.
*/

void	ft_place_empty(t_map *map, t_piece *piece, int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j < piece->x_len)
	{
		i = 0;
		while (i < piece->y_len)
		{
			if (piece->arr[i][j] == piece->letter)
				map->arr[y + i][x + j] = '.';
			i++;
		}
		j++;
	}
}
