/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:57:20 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/11 19:23:17 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_points(t_filler *filler)
{
	filler->result.x = 0;
	filler->result.y = 0;
	filler->st_my.x = 0;
	filler->st_my.y = 0;
	filler->st_en.x = 0;
	filler->st_en.y = 0;
}

void	read_player(t_filler *filler)
{
	char	*str;

	init_points(filler);
	get_next_line(0, &str);
	filler->my = (ft_strchr(str, '1')) ? 'O' : 'X';
	filler->en = (ft_strchr(str, '2')) ? 'O' : 'X';
	free(str);
}

void	read_map(t_filler *filler)
{
	char	*str;
	int		i;

	get_next_line(0, &str);
	filler->map_size.x = ft_atoi(ft_strchr(str, ' '));
	free(str);
	str = ft_strchr(str, ' ') + 1;
	filler->map_size.y = ft_atoi(ft_strchr(str, ' '));
	get_next_line(0, &str);
	i = 0;
	filler->map = (char **)malloc(sizeof(char *) * (filler->map_size.x + 1));
	while (i < filler->map_size.x)
	{
		free(str);
		get_next_line(0, &str);
		filler->map[i] = ft_strdup(ft_strchr(str, '.'));
		i++;
	}
	free(str);
	filler->map[i] = NULL;
}

void	read_figure(t_filler *filler)
{
	char	*str;
	int		i;

	get_next_line(0, &str);
	filler->fig_size.x = ft_atoi(ft_strchr(str, ' '));
	free(str);
	str = ft_strchr(str, ' ') + 1;
	filler->fig_size.y = ft_atoi(ft_strchr(str, ' '));
	i = 0;
	filler->figure = (char **)malloc(sizeof(char *) * (filler->fig_size.x + 1));
	while (i < filler->fig_size.x)
	{
		get_next_line(0, &str);
		filler->figure[i] = ft_strdup(str);
		i++;
		free(str);
	}
	filler->figure[i] = NULL;
}
