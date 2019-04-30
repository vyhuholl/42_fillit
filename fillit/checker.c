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

t_piece	*ft_construct_piece(char *input, char L)
{
	
}

/* a function which returns a tetrimino marked with letter L if input is valid, NULL otherwise*/

t_piece	*ft_is_ok(char *input, char L)
{
	int	i;
	int	count;

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
	return (ft_construct_piece(input, L));
}
