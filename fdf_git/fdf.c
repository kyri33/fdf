/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 15:18:41 by kioulian          #+#    #+#             */
/*   Updated: 2016/06/23 17:10:20 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialise_mlx(void **mlx, void **win)
{
	*mlx = mlx_init();
	initialise_win(*mlx, win);
}

void	initialise_win(void *mlx, void **win)
{
	*win = mlx_new_window(mlx, WIN_X, WIN_Y, "FDF");
}
