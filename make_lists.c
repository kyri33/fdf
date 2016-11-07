/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:33:56 by kioulian          #+#    #+#             */
/*   Updated: 2016/11/07 13:38:15 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	addnode(t_list **s, char **name)
{
	if (*s == NULL)
	{
		*s = (t_list *)malloc(sizeof(t_list));
		(*s)->content = name;
		(*s)->next = NULL;
	}
	else
		addnode(&((*s)->next), name);
}

void	set_width(t_env *e)
{
	while (e->list->content[e->len] != 0)
		e->len++;
	if (e->len > 200)
		e->width = 1;
	else if (e->len > 100)
		e->width = 4;
	else if (e->len > 50)
		e->width = 20;
	else
		e->width = 40;
	initialise_mlx(&e->mlx);
	if (compute_coord(e) == -1)
	{
		ft_putstr("Invalid line length");
		exit(1);
	}
}
