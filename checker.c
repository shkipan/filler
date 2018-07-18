/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 19:23:22 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/18 20:06:23 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

short	count_touch(t_filler *filler, char x, char y)
{
	short	i;
	short	j;
	char	touch;

	touch = 0;
	i = -1;
	while (++i < filler->fig_size.x)
	{
		j = -1;
		while (++j < filler->fig_size.y)
		{
			if (filler->figure[i][j] == '*' &&
					filler->map[i + x][j + y] == filler->my)
				touch++;
		}
	}
	if (touch != 1)
		return (0);
	return (1);
}

short	is_aval(t_filler *filler, char x, char y)
{
	int		i;
	int		j;
	char	touch;

	i = -1;
	touch = 0;
	while (++i < filler->fig_size.x)
	{
		j = -1;
		while (++j < filler->fig_size.y)
		{
			if (filler->figure[i][j] == '*' && (x + i < 0 || y + j < 0 ||
						x + i >= filler->map_size.x ||
						y + j >= filler->map_size.y))
				return (0);
			if (filler->figure[i][j] == '*' &&
					filler->map[i + x][j + y] == filler->en)
				return (0);
		}
	}
	return (count_touch(filler, x, y));
}
