/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 09:05:45 by kioulian          #+#    #+#             */
/*   Updated: 2016/11/07 13:47:33 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	save_xy(t_coord **ptr, t_env *e, int z)
{
	int	x;
	int	y;
	int	x_i;
	int	y_i;

	x_i = e->x;
	y_i = e->y;
	x = (x_i * 1 / 1.41421 + z * 1 / 1.41421) * e->width + X_OFFSET;
	y = (x_i * 1 / 2.44948 + y_i * 0.81649 - z * 1 / 2.44948)
		* e->width + Y_OFFSET;
	if (*ptr == NULL)
	{
		*ptr = (t_coord *)malloc(sizeof(t_coord));
		e->delete = e->delete + 1;
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
