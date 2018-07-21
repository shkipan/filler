/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 20:02:11 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/20 20:34:05 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	print_champs(char *line)
{
	int	x;
	int y;

	x = ft_atoi(ft_strchr(line, ':') + 1);
	y = ft_atoi(ft_strrchr(line, ':') + 1);
	ft_printf("first player got %{red}d points!\n", x);
	ft_printf("second player got %{red}d points!\n", y);
	if (x > y)
		ft_printf("%{mag}s\n", "FIRST PLAYER WON!!!");
	else
		ft_printf("%{mag}s\n", "SECOND PLAYER WON!!!");
}

void	console_visualizer(char *line)
{
	int		i;
	int		pos;

	i = -1;
	pos = 0;
	while (line[++i] != '=')
	{
		if (line[i] == '\n')
			pos = i;
		if (ft_isdigit(line[pos + 1]) && line[i] == 'O')
			ft_printf("%{red}c", line[i]);
		else if (ft_isdigit(line[pos + 1]) && line[i] == 'o')
			ft_printf("%{mag}c", line[i]);
		else if (ft_isdigit(line[pos + 1]) && line[i] == 'X')
			ft_printf("%{blu}c", line[i]);
		else if (ft_isdigit(line[pos + 1]) && line[i] == 'x')
			ft_printf("%{cya}c", line[i]);
		else if (line[i] == '.')
			ft_printf("%{yel}c", line[i]);
		else if (line[i] == '*')
			ft_printf("%{grn}c", line[i]);
		else
			ft_printf("%c", line[i]);
	}
	print_champs(line + i);
}
