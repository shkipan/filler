/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:30:40 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/08 21:14:02 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_map(t_filler *filler)
{
	int i;

	i = -1;
	while (++i < filler->field.x)
		ft_printf("%s\n", filler->map[i]);
}

int		main(void)
{
	t_filler	*filler;
	char		key;

	filler = (t_filler *)malloc(sizeof(t_filler));
	read_player(filler);
	key = 0;
	while (1)
	{
		read_map(filler);
		print_map(filler);
		key = 1;
		if (key == 1)
		{
			freesher(filler);
			ft_printf("%d %d\n_______\n", filler->result.x, filler->result.y);
			system("leaks filler");
			return (0);
		}
	}
	return (0);
}
