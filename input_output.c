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

/*
** A function which reads a list of tetriminos from the file descriptor.
*/

t_list	*ft_read(int fd)
{
	t_list	*list;
	t_piece	*piece;
	char	*buffer;
	char	current;
	int		len;

	buffer = ft_strnew(21);
	list = NULL;
	current = 'A';
	while ((len = read(fd, buffer, 21)) >= 20)
	{
		if (!(piece = ft_construct_piece(buffer, current++, len)))
		{
			ft_memdel((void**)&buffer);
			return (ft_free_list(list));
		}
		ft_lstadd(&list, ft_lstnew(piece, sizeof(t_piece)));
		ft_memdel((void**)&piece);
	}
	ft_memdel((void**)&buffer);
	if (len != 0)
		return (ft_free_list(list));
	ft_lstrev(&list);
	return (list);
}

/*
** A function which frees a tetrimino.
*/

void	ft_free_piece(t_piece *piece)
{
	int	i;

	i = 0;
	while (i < piece->y_len)
	{
		ft_memdel((void**)&(piece->arr[i]));
		i++;
	}
	ft_memdel((void**)&(piece->arr));
	ft_memdel((void**)&piece);
}

/*
** A function which frees a list and returns NULL --
** in case our input is invalid, or if we solved a map.
*/

t_list	*ft_free_list(t_list *list)
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
	return (NULL);
}

/*
** A function which frees a map.
*/

void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
		ft_memdel((void**)&map->arr[i++]);
	ft_memdel((void**)&map->arr);
	ft_memdel((void**)&map);
}

/*
** A function which prints a map.
*/

void	ft_print(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->arr[i]);
		ft_putchar('\n');
		i++;
	}
}
