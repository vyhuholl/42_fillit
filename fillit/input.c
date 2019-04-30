/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 20:58:13 by sghezn            #+#    #+#             */
/*   Updated: 2019/04/27 20:58:16 by sghezn           ###   ########.fr       */
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
