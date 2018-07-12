/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 18:35:14 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/12 19:55:23 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	fill_my_player(t_filler *filler, short x, short y)
{
	if (filler->st_my.x >= 0 && filler->st_my.y >= 0)
		return ;
	filler->st_my.x = x;
	filler->st_my.y = y;
}

void	fill_en_player(t_filler *filler, short x, short y)
{
	if (filler->st_en.x >= 0 && filler->st_en.y >= 0)
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
				if (filler->map[i][j] == filler->my)
					fill_my_player(filler, i, j);
				if (filler->map[i][j] == filler->en)
					fill_en_player(filler, i, j);
			}
		}
	}
	filler->dist = find_distance(filler,
				filler->st_my.x, filler->st_my.y, 1);
}

short	find_distance(t_filler *filler, short x, short y, int dist)
{
	short	i;
	short	j;

	i = x - dist - 1;
	while (++i <= x + dist)
	{
		j = y - dist - 1;
		while ((i == x - dist || i == x + dist) && ++j <= y + dist)
			if (IN_BORDER_X(i) && IN_BORDER_Y(y - dist) &&
					filler->map[i][y - dist] == filler->en)
				return (dist);
		if (IN_BORDER_X(i) && IN_BORDER_Y(y - dist) &&
				filler->map[i][y - dist] == filler->en)
			return (dist);
		if (IN_BORDER_X(i) && IN_BORDER_Y(y + dist) &&
				filler->map[i][y + dist] == filler->en)
			return (dist);
	}
	dist = find_distance(filler, x, y, dist + 1);
	return (dist);
}
