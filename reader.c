/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:57:20 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/08 21:14:01 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	read_player(t_filler *filler)
{
	char	*str;

	get_next_line(0, &str);
	filler->my = (ft_strchr(str, '1')) ? 'O' : 'X';
	filler->enemy = (ft_strchr(str, '1')) ? 'X' : 'O';
	filler->result.x = 1;
	filler->result.y = 1;
	free(str);
}

void	read_map(t_filler *filler)
{
	char	*str;
	int		i;

	get_next_line(0, &str);
	filler->field.x = ft_atoi(ft_strchr(str, ' '));
	free(str);
	str = ft_strchr(str, ' ') + 1;
	filler->field.y = ft_atoi(ft_strchr(str, ' '));
	get_next_line(0, &str);
	i = -1;
	filler->map = (char **)malloc(sizeof(char *) * (filler->field.x + 1));
	while (++i < filler->field.x)
	{
		free(str);
		get_next_line(0, &str);
		filler->map[i] = ft_strdup(ft_strchr(str, '.')); 
	}
	free(str);
	filler->map[i] = NULL;
}

void	freesher(t_filler *filler)
{
	int i;

	i = -1;
	while (++i < filler->field.x)
		free(filler->map[i]);
	free(filler->map);
	free(filler);
}
