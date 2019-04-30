/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 20:58:55 by sghezn            #+#    #+#             */
/*   Updated: 2019/04/27 20:58:57 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
		ft_memdel((void**)&map->arr[i++]);
	ft_memdel((void**)&map->arr);
	ft_memdel((void**)&map);
}

void	ft_print(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->arr[i]);
		ft_putchar('\n');
		ft_memdel((void**)&map->arr[i]);
		i++;
	}
	ft_memdel((void**)&map->arr);
	ft_memdel((void**)&map);
}
