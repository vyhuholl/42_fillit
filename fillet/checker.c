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

int	ft_is_char_ok(char **tetrimino, int i, int j)
{
	if (tetrimino[i][j] == '.')
		return (1);
	else if (tetrimino[i][j] == '#')
	{
		if (i > 0 && tetrimino[i - 1][j] == '#')
			return (1);
		if (i < 3 && tetrimino[i + 1][j] == '#')
			return (1);
		if (j > 0 && tetrimino[i][j - 1] == '#')
			return (1);
		if (j < 3 && tetrimino[i][j + 1] == '#')
			return (1);
	}
	return (0);
}

int	ft_is_ok(char **tetrimino)
{
	int	i;
	int	j;
	int count;

	count = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (!ft_is_char_ok(tetrimino, i, j))
				return (0);
			if (tetrimino[i][j] == '#')
				count++;
			j++;
		}
		if (tetrimino[i][j])
			return (0);
		i++;
	}
	if (tetrimino[i] || count != 4)
		return (0);
	return (1);
}
