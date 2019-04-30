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

/* a function which frees a tetrimino */

void	ft_free_piece(t_piece *piece)
{
	int	i;

	i = 0;
	while (i < piece->y_len)
	{
		ft_memdel((void**)&(piece->place[i]));
		i++;
	}
	ft_memdel((void**)&(piece->place));
	ft_memdel((void**)&piece);
}

/* a function which frees a list -- in case our input is invalid, or we solved a map */

void	ft_free_list(t_list *list)
{
	t_list	*ptr;
	t_piece	*piece;

	while (list)
	{
		piece = (t_piece*)list->content;
		ptr = list->next;
		ft_free_piece(piece);
		ft_memdel((void**)&list);
		list = ptr;
	}
}

/* a function which frees a map */

void	ft_free_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->size)
		ft_memdel((void**)&map->arr[i++]);
	ft_memdel((void**)&map->arr);
	ft_memdel((void**)&map);
}

/* a function which prints a map, immediately freeing it after */

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
