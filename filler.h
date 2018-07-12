/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:45:03 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/11 19:59:58 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"

typedef struct	s_point
{
	char		x;
	char		y;
}				t_point;

typedef struct	s_filler
{
	char		my;
	char		en;
	t_point		map_size;
	t_point		fig_size;
	t_point		st_my;
	t_point		st_en;
	t_point		result;
	char		**map;
	char		**figure;
}				t_filler;

void			find_players(t_filler *filler);

int				is_aval(t_filler *filler, char x, char y);

void			read_player(t_filler *filler);
void			read_map(t_filler *filler);
void			read_figure(t_filler *filler);
void			freesher(t_filler *filler);

#endif
