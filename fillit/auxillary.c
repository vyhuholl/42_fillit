/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxillary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 20:23:00 by sghezn            #+#    #+#             */
/*   Updated: 2019/05/05 20:23:02 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_get_x_len(char *input)
{

}

int		ft_get_y_len(char *input)
{
	
}

/* a function which checks whether a block of a tetrimino at (x, y) position */
/* touches at least one other block */

int		ft_touches(t_piece *piece, char L, int x, int y)
{
	if (x > 0 && piece->arr[x - 1][y] == L)
		return (1);
	if (y > 0 && piece->arr[x][y - 1] == L)
		return (1);
	if (x < piece->x_len - 1 && piece->arr[x + 1][y] == L)
		return (1);
	if (y < piece->y_len - 1 && piece->arr[x][y + 1] == L)
		return (1);
	return (0);
}
