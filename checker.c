/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 19:23:22 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/11 20:48:29 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		is_aval(t_filler *filler, char x, char y)
{
	int		i;
	int		j;

	i = -1;
//	ft_printf("%{red}d %{red}d\n", x, y);
	while (++i < filler->fig_size.x)
	{
		j = -1;
		while (++j < filler->fig_size.y)
		{
			if (filler->figure[i][j] == '*' && (x + i < 0 || y + j < 0 ||
						x + i >= filler->map_size.x ||
						y + j >= filler->map_size.y))
				return (0);
//			ft_printf("%d %d %c %c\n", i, j, filler->figure[i][j], filler->map[i + x][j + y]);
			if (filler->figure[i][j] == '*' &&
					(filler->map[i + x][j + y] == filler->en ||
					 filler->map[i + x][j + y] == filler->en + 32))
				return (0);
		}
	}
	return (1);
}
