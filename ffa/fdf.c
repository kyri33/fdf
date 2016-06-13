/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 15:18:41 by kioulian          #+#    #+#             */
/*   Updated: 2016/05/31 09:25:28 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialise_mlx(void **mlx)
{
	*mlx = mlx_init();
}

void	initialise_win(void *mlx, void **win)
{
	*win = mlx_new_window(mlx, WIN_X, WIN_Y, "FDF");
}
