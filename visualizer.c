/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:10:27 by dskrypny          #+#    #+#             */
/*   Updated: 2018/07/25 16:23:04 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static void	handle_a_char(char linei, char line)
{
	if (ft_isdigit(line) && linei == 'O')
		ft_printf("%{red}c", linei);
	else if (ft_isdigit(line) && linei == 'o')
		ft_printf("%{mag}c", linei);
	else if (ft_isdigit(line) && linei == 'X')
		ft_printf("%{blu}c", linei);
	else if (ft_isdigit(line) && linei == 'x')
		ft_printf("%{cya}c", linei);
	else if (linei == '.')
		ft_printf("%{yel}c", linei);
	else
		ft_printf("%c", linei);
}

static int	print_line(char *line)
{
	int		i;

	if (line[0] != '=' && !ft_isdigit(line[0]))
	{
		if (line[0] == '<')
			ft_printf("\033[0;0f");
		return (0);
	}
	if (line[0] == '=')
		return (1);
	i = -1;
	while (line[++i])
	{
		if (ft_isdigit(line[i]) && i < 3)
			continue ;
		handle_a_char(line[i], line[0]);
	}
	ft_printf("\n");
	return (0);
}

static void	print_result(char *line, char *player1, char *player2)
{
	int x1;
	int x2;

	ft_printf(CLEAR_SCR);
	x1 = ft_atoi(ft_strchr(line, ':') + 1);
	ft_printf("%{red}s %{grn}s %{red}d %{grn}s", player1, "got",
			x1, "points\n");
	get_next_line(0, &line);
	x2 = ft_atoi(ft_strchr(line, ':') + 1);
	ft_printf("%{blu}s %{grn}s %{red}d %{grn}s", player2, "got",
			x2, "points\n");
	ft_printf("%{mag}s %{mag}s\n", (x1 > x2) ? player1 :
			player2, "WON");
	free(line);
}

static void	read_players(char **player1, char **player2)
{
	char	*line;
	char	*temp;

	get_next_line(0, &line);
	free(line);
	get_next_line(0, &line);
	*player1 = ft_strdup(ft_strchr(line, '[') + 1);
	temp = *player1;
	*player1 = ft_str_cut(*player1, ft_strlen(*player1) - 1);
	free(temp);
	free(line);
	get_next_line(0, &line);
	free(line);
	get_next_line(0, &line);
	*player2 = ft_strdup(ft_strchr(line, '[') + 1);
	temp = *player2;
	*player2 = ft_str_cut(*player2, ft_strlen(*player2) - 1);
	free(temp);
	free(line);
}

int			main(void)
{
	char	*line;
	char	*player1;
	char	*player2;
	int		i;

	i = -1;
	while (++i < 5)
	{
		get_next_line(0, &line);
		free(line);
	}
	read_players(&player1, &player2);
	ft_printf(CLEAR_SCR);
	ft_printf("\033[0;0f");
	while (get_next_line(0, &line))
	{
		if (print_line(line))
			print_result(line, player1, player2);
		free(line);
	}
	free(player1);
	free(player2);
	return (0);
}
