/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 19:23:22 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/21 09:32:10 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

short	is_aval(t_filler *filler, char x, char y)
{
	int		i;
	int		j;
	char	touch;

	i = filler->st_fig.x - 1;
	j = filler->st_fig.y - 1;
	touch = 0;
	while (++i <= filler->end_fig.x)
	{
		while (++j <= filler->end_fig.y)
		{
			if (filler->figure[i][j] == '*' && (x + i < 0 || y + j < 0 ||
						x + i >= filler->map_size.x ||
						y + j >= filler->map_size.y))
				return (0);
			if (filler->figure[i][j] == '*' &&
					filler->map[i + x][j + y] == filler->en)
				return (0);
			if (filler->figure[i][j] == '*' &&
					filler->map[i + x][j + y] == filler->my)
				touch++;
		}
		j = filler->st_fig.y - 1;
	}
	return ((touch != 1) ? 0 : 1);
}
