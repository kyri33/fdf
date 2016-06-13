/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 10:58:19 by kioulian          #+#    #+#             */
/*   Updated: 2016/06/05 15:17:46 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdio.h"

void	draw_line(t_vect point1, t_vect point2, t_env *e)
{
	float	m;
	float	c;
	int		x;
	int		end;

	x = point1.x;
	end = point2.x;
	if (point2.x == point1.x)
		draw_verticle(point1, point2, e);
	else
	{
		m = (point2.y - point1.y) / (double)(point2.x - point1.x);
		c = point1.y - m * point1.x;
		if (point2.x < point1.x)
		{
			x = point2.x;
			end = point1.x;
		}
		while (x <= end)
		{
			mlx_pixel_put(e->mlx, e->win, x, m * x + c, COLOR);
			x++;
		}
	}
}

void	draw_verticle(t_vect point1, t_vect point2, t_env *e)
{
	int	y_end;
	int	y;

	y_end = point2.y;
	y = point1.y;
	if (point2.y < point1.y)
	{
		y = point2.y;
		y_end = point1.y;
	}
	while (y <= y_end)
	{
		mlx_pixel_put(e->mlx, e->win, point1.x, y, COLOR);
		y++;
	}
}

void	draw_rows(t_env *e)
{
	t_coord *temp;
	t_vect	point1;
	t_vect	point2;

	temp = e->ptr;
	while (temp->next != NULL)
	{
		point1.x = temp->x;
		point1.y = temp->y;
		point2.x = temp->next->x;
		point2.y = temp->next->y;
		if (temp->x_i != e->len - 1)
			draw_line(point1, point2, e);
		if (temp->y_i < e->height)
			draw_line(point1, find_below(temp), e);
		temp = temp->next;
	}
}

t_vect	find_below(t_coord *ptr)
{
	t_coord	*temp;
	int		x;
	int		y;
	t_vect	point;

	x = ptr->x_i;
	y = ptr->y_i;
	temp = ptr->next;
	while (temp != NULL)
	{
		if (temp->x_i == x && temp->y_i == y + 1)
		{
			point.x = temp->x;
			point.y = temp->y;
			return (point);
		}
		temp = temp->next;
	}
	point.y = ptr->y;
	point.x = ptr->x;
	return (point);
}
