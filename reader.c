/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:57:20 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/25 12:53:02 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	init_points(t_filler *filler)
{
	filler->result.x = 0;
	filler->result.y = 0;
	filler->st_my.x = -1;
	filler->st_my.y = -1;
	filler->st_en.x = -1;
	filler->st_en.y = -1;
	filler->st_fig.x = -1;
	filler->st_fig.y = 1000;
	filler->end_fig.x = 0;
	filler->end_fig.y = 0;
	filler->dist = 1000000;
	filler->my_count = 0;
	filler->fig_count = 0;
}

void		read_map(t_filler *filler)
{
	char	*str;
	int		i;

	init_points(filler);
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
		filler->map[i] = ft_strdup(str + 4);
		ft_strcapit(filler->map[i]);
		i++;
	}
	free(str);
	filler->map[i] = NULL;
}

static void	find_start_end(t_filler *filler)
{
	int		i;
	int		j;

	i = filler->st_fig.x - 1;
	while (++i < filler->fig_size.x)
	{
		j = -1;
		while (++j < filler->fig_size.y)
		{
			if (filler->figure[i][j] == '*' && j > filler->end_fig.y)
				filler->end_fig.y = j;
			if (filler->figure[i][j] == '*' && j < filler->st_fig.y)
				filler->st_fig.y = j;
		}
	}
	i = filler->fig_size.x;
	while (--i >= 0)
		if (ft_strchr(filler->figure[i], '*') && i > filler->end_fig.x)
			filler->end_fig.x = i;
}

void		read_figure(t_filler *filler)
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
		if (ft_strchr(str, '*') && filler->st_fig.x < 0)
			filler->st_fig.x = i;
		i++;
		free(str);
	}
	filler->figure[i] = NULL;
	find_start_end(filler);
}

void		count_sym(t_filler *filler)
{
	short	i;
	short	j;

	i = -1;
	while (++i < filler->map_size.x)
	{
		j = -1;
		while (++j < filler->map_size.y)
			if (filler->map[i][j] == filler->my)
				filler->my_count++;
	}
	i = -1;
	while (++i < filler->fig_size.x)
	{
		j = -1;
		while (++j < filler->fig_size.y)
			if (filler->figure[i][j] == filler->my)
				filler->fig_count++;
	}
}
