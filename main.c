/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:30:40 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/18 19:56:13 by dskrypny         ###   ########.fr       */
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
}

void	freesher(t_filler *filler)
{
	int i;

	i = -1;
	if (filler == NULL)
		return ;
	while (++i < filler->map_size.x)
		free(filler->map[i]);
	free(filler->map);
	i = -1;
	while (++i < filler->fig_size.x)
		free(filler->figure[i]);
	free(filler->figure);
}

int		main(void)
{
	t_filler	*filler;
	char		key;

	filler = (t_filler *)malloc(sizeof(t_filler));
	read_player(filler);
	key = 1;
	while (1)
	{
		read_map(filler);
		read_figure(filler);
		count_sym(filler);
		find_players(filler);
		search_min(filler);
		ft_printf("%d %d\n", filler->result.x, filler->result.y);
		freesher(filler);
	}
	free(filler);
	return (0);
}
