/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 22:16:16 by sghezn            #+#    #+#             */
/*   Updated: 2019/04/08 14:29:26 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if (!(list = (t_list*)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		list->content = ft_memalloc(content_size);
		if (!list->content)
		{
			ft_memdel((void**)&list);
			return (NULL);
		}
		ft_memcpy(list->content, content, content_size);
	}
	list->content_size = content_size;
	list->next = NULL;
	return (list);
}
