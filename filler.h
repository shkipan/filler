/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:45:03 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/08 21:14:06 by dskrypny         ###   ########.fr       */
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
	char		enemy;
	t_point		field;
	t_point		result;
	char		**map;
}				t_filler;

void			read_player(t_filler *filler);
void			read_map(t_filler *filler);
void			freesher(t_filler *filler);

#endif
