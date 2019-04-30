/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghezn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 20:55:50 by sghezn            #+#    #+#             */
/*   Updated: 2019/04/27 20:55:52 by sghezn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_list	*input;
	t_map	*solution;

	if (argc == 2)
	{
		if (!(input = ft_read(open(argv[1], O_RDONLY))))
			ft_putstr("error\n");
		else
		{
			solution = ft_solve(input);
			ft_print(solution);
		}
	}
	else
		ft_putstr("usage: fillit source_file\n");
	return (0);
}
