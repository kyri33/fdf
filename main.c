/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 11:57:18 by kioulian          #+#    #+#             */
/*   Updated: 2016/11/07 13:35:42 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	get_key_event(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int	perform_check(int argc, char **argv, t_env *e)
{
	if (argc != 2)
	{
		ft_putstr("No file specified");
		return (0);
	}
	if ((e->fd = open(argv[1], O_RDONLY, 0)) == -1)
	{
		ft_putstr("Error reading file");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_env	e;

	e.len = 0;
	e.delete = 0;
	e.height = 0;
	if (perform_check(argc, argv, &e) == -1)
		exit(0);
	e.list = NULL;
	while (get_next_line(e.fd, &e.data) > 0)
	{
		e.value = ft_strsplit(e.data, ' ');
		addnode(&e.list, e.value);
		e.height++;
	}
	set_width(&e);
	initialise_win(e.mlx, &e.win);
	draw_rows(&e);
	mlx_key_hook(e.win, get_key_event, 0);
	mlx_loop(e.mlx);
	close(e.fd);
	return (1);
}
