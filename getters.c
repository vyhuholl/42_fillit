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

/*
** Utility functions used to construct tetriminos from 1-d char array of input.
*/

int		ft_get_start(char *input, int n)
{
	int	i;
	int	x_start;
	int	y_start;

	x_start = 4;
	y_start = 4;
	i = 0;
	while (i < 20)
	{
		if (input[i] == '#')
		{
			if (i % 5 < x_start)
				x_start = i % 5;
			if (i / 5 < y_start)
				y_start = i / 5;
		}
		i++;
	}
	return (x_start + (n + y_start) * 5);
}

int		ft_get_x_len(char *input)
{
	int	i;
	int	start;
	int	end;

	start = 4;
	end = -1;
	i = 0;
	while (i < 20)
	{
		if (input[i] == '#')
		{
			if (i % 5 < start)
				start = i % 5;
			if (i % 5 > end)
				end = i % 5;
		}
		i++;
	}
	return (end - start + 1);
}

int		ft_get_y_len(char *input)
{
	int	i;
	int	start;
	int	end;

	start = 4;
	end = -1;
	i = 0;
	while (i < 20)
	{
		if (input[i] == '#')
		{
			if (i / 5 < start)
				start = i / 5;
			if (i / 5 > end)
				end = i / 5;
		}
		i++;
	}
	return (end - start + 1);
}
