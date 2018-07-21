/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 17:55:10 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/20 20:37:15 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	graphic_visualizer(char *res)
{
	res[0] = res[0];
}

int		usage(void)
{
	ft_printf("%{grn}s", "Usage: ./vm X\nWhere X is:\n");
	ft_printf("1 - console visualizer with colors\n");
	ft_printf("2 - mlx visualizer\n");
	ft_printf("_______________________________________\n");
	return (0);
}

int		main(int ac, char **av)
{
	char	*line;
	char	*temp;
	char	*res;

	if (ac != 2)
		return (usage());
	res = ft_strdup("");
	while (get_next_line(0, &line))
	{
		temp = res;
		res = ft_strjoin(res, line);
		free(temp);
		free(line);
		temp = res;
		res = ft_strjoin(res, "\n");
		free(temp);
	}
	if (!ft_strcmp(av[1], "1"))
		console_visualizer(res);
	if (!ft_strcmp(av[1], "2"))
		graphic_visualizer(res);
	free(res);
	return (0);
}
