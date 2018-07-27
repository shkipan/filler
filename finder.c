/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 18:35:14 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/25 12:58:50 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
				if (filler->map[i][j] == filler->my &&
						(filler->st_my.x == -1 && filler->st_my.y == -1))
				{
					filler->st_my.x = i;
					filler->st_my.y = j;
				}
			}
		}
	}
}

short	find_distance_sym(t_filler *filler, short x, short y, int dist)
{
	short	i;
	short	j;

	i = x - dist - 1;
	while (++i <= x + dist)
	{
		if (IN_BORDER_X(i) && IN_BORDER_Y(y - dist) &&
				filler->map[i][y - dist] == filler->en)
			return (dist);
		if (IN_BORDER_X(i) && IN_BORDER_Y(y + dist) &&
				filler->map[i][y + dist] == filler->en)
			return (dist);
	}
	j = y - dist - 1;
	while (++j <= y + dist)
	{
		if (IN_BORDER_X(x - dist) && IN_BORDER_Y(j) &&
				filler->map[x - dist][j] == filler->en)
			return (dist);
		if (IN_BORDER_X(x + dist) && IN_BORDER_Y(j) &&
				filler->map[x + dist][j] == filler->en)
			return (dist);
	}
	dist = find_distance_sym(filler, x, y, dist + 1);
	return (dist);
}

int		count_distance(t_filler *filler, int x, int y)
{
	short	i;
	short	j;
	int		res;

	i = filler->st_fig.x - 1;
	j = filler->st_fig.y - 1;
	res = 0;
	while (++i <= filler->end_fig.x)
	{
		while (++j <= filler->end_fig.y)
		{
			if (filler->figure[i][j] == '*')
				res += find_distance_sym(filler, x + i, y + j, 1);
		}
		j = filler->st_fig.y - 1;
	}
	return (res);
}

void	spin_figure(t_filler *filler, int x, int y)
{
	int		temp;
	short	i;
	short	j;

	i = -1;
	while (++i <= filler->end_fig.x)
	{
		j = -1;
		while (++j <= filler->end_fig.y)
		{
			if (is_aval(filler, x - i, y - j))
			{
				temp = count_distance(filler, x - i, y - j);
				if (((x - i) != 0 && (y - j) != 0) &&
						((temp <= filler->dist && filler->my == 'O')
						|| (temp < filler->dist && filler->my == 'X')))
				{
					filler->dist = temp;
					filler->result.x = x - i;
					filler->result.y = y - j;
				}
			}
		}
	}
}

void	search_min(t_filler *filler)
{
	short i;
	short j;

	i = filler->st_my.x - 1;
	j = filler->st_my.y - 1;
	while (++i < filler->map_size.x)
	{
		while (++j < filler->map_size.y)
		{
			if (filler->map[i][j] == filler->my)
			{
				spin_figure(filler, i, j);
				filler->my_count--;
				if (!filler->my_count)
					return ;
			}
		}
		j = -1;
	}
}
