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

int		ft_get_x_start(char *input)
{
	int	i;
	int	start;

	start = 4;
	i = 0;
	while (i < 20)
	{
		if (input[i] == '#' && i % 5 < start)
			start = i % 5;
		i++;
	}
	return (start);
}

int		ft_get_x_end(char *input)
{
	int	i;
	int	end;

	end = -1;
	i = 0;
	while (i < 20)
	{
		if (input[i] == '#' && i % 5 > end)
			end = i % 5;
		i++;
	}
	return (end);
}

int		ft_get_y_start(char *input)
{
	int	i;
	int	start;

	start = 4;
	i = 0;
	while (i < 20)
	{
		if (input[i] == '#' && i / 5 < start)
			start = i / 5;
		i++;
	}
	return (start);
}

int		ft_get_y_end(char *input)
{
	int	i;
	int	end;

	end = -1;
	i = 0;
	while (i < 20)
	{
		if (input[i] == '#' && i / 5 > end)
			end = i / 5;
		i++;
	}
	return (end);
}

char	**ft_get_arr(char *input, int x_len, int y_len, char letter)
{
	char	**arr;
	int		i;
	int		x_start;
	int		y_start;

	x_start = ft_get_x_start(input);
	y_start = ft_get_y_start(input);
	arr = ft_memalloc(sizeof(char*) * (y_len + 1));
	i = 0;
	while (i < y_len + 1)
	{
		arr[i] = ft_strnew(x_len + 1);
		i++;
	}
	i = 0;
	while (i < 20)
	{
		if (i % 5 >= x_start && i % 5 <= x_start + x_len &&
			i / 5 >= y_start && i / 5 <= y_start + y_len)
			arr[i / 5 - y_start][i % 5 - x_start] = CHECK(input, i, letter);
		i++;
	}
	return (arr);
}
