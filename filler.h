/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:45:03 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/25 16:06:11 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
# define IN_BORDER_X(i) (i >= 0 && i < filler->map_size.x)
# define IN_BORDER_Y(i) (i >= 0 && i < filler->map_size.y)

typedef struct	s_point
{
	short		x;
	short		y;
}				t_point;

typedef struct	s_filler
{
	char		**map;
	char		**figure;
	char		*player1;
	char		*player2;
	t_point		map_size;
	t_point		fig_size;
	t_point		st_my;
	t_point		st_en;
	t_point		st_fig;
	t_point		end_fig;
	t_point		result;
	int			dist;
	int			my_count;
	int			fig_count;
	char		my;
	char		en;
}				t_filler;

void			find_players(t_filler *filler);
short			find_distance_sym(t_filler *filler, short x, short y, int dist);
void			search_min(t_filler *filler);

short			is_aval(t_filler *filler, char x, char y);

void			read_map(t_filler *filler);
void			read_figure(t_filler *filler);
void			count_sym(t_filler *filler);

#endif
