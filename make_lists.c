/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:33:56 by kioulian          #+#    #+#             */
/*   Updated: 2016/05/25 11:56:22 by kioulian         ###   ########.fr       */
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
