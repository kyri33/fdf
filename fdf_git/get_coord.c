/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 09:05:45 by kioulian          #+#    #+#             */
/*   Updated: 2016/06/05 17:32:55 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	save_xy(t_coord **ptr, t_env *e, int z)
{
	int	x;
	int	y;
	int	x_i;
	int	y_i;

	x_i = 0;
	y_i = 0;
	x = 0;
	y = 0;
	if (*ptr == NULL)
	{
		x_i = e->x;
		y_i = e->y;
		x = (x_i * 1 / 1.4142 + z * 1 / 1.4142) * e->width + X_OFFSET;
		y = (x_i * 1 / 2.4494 + y_i * 0.8164 - z * 1 / 2.4494)
			* e->width + Y_OFFSET;
		*ptr = (t_coord *)malloc(sizeof(t_coord));
		(*ptr)->x = x;
		(*ptr)->y = y;
		(*ptr)->x_i = x_i;
		(*ptr)->y_i = y_i;
		(*ptr)->next = NULL;
	}
	else
		save_xy(&((*ptr)->next), e, z);
}

int		compute_coord(t_env *e)
{
	t_list	*tmp;

	tmp = e->list;
	while (tmp != NULL)
	{
		e->x = 0;
		while (tmp->content[e->x] != 0)
		{
			save_xy(&e->ptr, e, ft_atoi(tmp->content[e->x]));
			e->x++;
		}
		if (e->x != e->len && e->x != 0)
			return (-1);
		e->y++;
		tmp = tmp->next;
	}
	return (1);
}
