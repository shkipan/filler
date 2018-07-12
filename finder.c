/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 18:35:14 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/11 19:42:54 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	fill_my_player(t_filler *filler, char x, char y)
{
	if (filler->st_my.x && filler->st_my.y)
		return ;
	filler->st_my.x = x;
	filler->st_my.y = y;
}

void	fill_en_player(t_filler *filler, char x, char y)
{
	if (filler->st_en.x && filler->st_en.y)
		return ;
	filler->st_en.x = x;
	filler->st_en.y = y;
}

void	find_players(t_filler *filler)
{
	int		i;
	int		j;

	i = -1;
	while (++i < filler->map_size.x)
	{
		j = -1;
		while (++j < filler->map_size.y)
		{
			if (filler->map[i][j] != '.')
			{
				if (filler->map[i][j] == filler->my ||
						filler->map[i][j] == filler->my + 32)
					fill_my_player(filler, i, j);
				if (filler->map[i][j] == filler->en ||
						filler->map[i][j] == filler->en + 32)
					fill_en_player(filler, i, j);
			}
		}
	}
}
