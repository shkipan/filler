/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:30:40 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/12 19:59:36 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_map(t_filler *filler)
{
	int i;

	i = -1;
	while (++i < filler->map_size.x)
		ft_printf("%s\n", filler->map[i]);
	i = -1;
	while (++i < filler->fig_size.x)
		ft_printf("%s\n", filler->figure[i]);
	ft_printf("%c %d %d\n", filler->my, filler->st_my.x, filler->st_my.y);
	ft_printf("%c %d %d\n", filler->en, filler->st_en.x, filler->st_en.y);
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
		read_figure(filler);
		find_players(filler);
		print_map(filler);
		filler->result.x = filler->st_my.x - filler->st_fig.x;
		filler->result.y = filler->st_my.y - filler->st_fig.y;
		key = 1;
		if (key == 1)
		{
			freesher(filler);
			ft_printf("%d %d\n", filler->result.x, filler->result.y);
			while (1)
				key = 1;
			return (0);
		}
	}
	return (0);
}

void	freesher(t_filler *filler)
{
	int i;

	i = -1;
	while (++i < filler->map_size.x)
		free(filler->map[i]);
	free(filler->map);
	i = -1;
	while (++i < filler->fig_size.x)
		free(filler->figure[i]);
	free(filler->figure);
	free(filler);
}
