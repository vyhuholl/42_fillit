/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 16:50:42 by sghezn            #+#    #+#             */
/*   Updated: 2019/05/09 16:50:43 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_piece(t_piece *piece)
{
	int	i;

	ft_putchar(piece->letter);
	ft_putchar('\n');
	ft_putchar(piece->x_len + 48);
	ft_putchar('\n');
	ft_putchar(piece->y_len + 48);
	i = 0;
	while (piece->arr[i])
	{
		ft_putstr(piece->arr[i]);
		ft_putchar('\n');
		i++;
	}
}

void	ft_print_list(t_list *list)
{
	t_list	*ptr;
	t_piece	*piece;

	ptr = list;
	while (ptr)
	{
		piece = (t_piece*)ptr->content;
		ft_print_piece(piece);
		ft_putchar('\n');
		ptr = ptr->next;
	}
}
