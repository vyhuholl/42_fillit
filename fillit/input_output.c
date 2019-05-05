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

/* a function which reads a list of tetriminos from the file descriptor */

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
	while ((len = read(fd, buffer, 21)) < 21)
	{
		if (!(piece = ft_is_ok(buffer, current++)))
		{
			ft_memdel((void**)&buf);
			free_list(list);
			return (NULL);
		}
		ft_lstadd(&list, ft_lstnew(piece, sizeof(s_piece)));
		ft_memdel((void**)&piece);
	}
	ft_memdel((void**)&buf);
	if (len != 0)
		return(free_list(list));
	ft_lstrev(&list);
	return (list);
}

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
