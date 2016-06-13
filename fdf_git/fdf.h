/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kioulian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:29:37 by kioulian          #+#    #+#             */
/*   Updated: 2016/06/05 16:21:56 by kioulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "libft/libft.h"
# include <mlx.h>
# include <math.h>

# define X_OFFSET 500
# define Y_OFFSET 100
# define COLOR 0x666666
# define WIN_X 1800
# define WIN_Y 1800

typedef struct	s_vect
{
	int	x;
	int	y;
}				t_vect;

typedef struct	s_list
{
	char			**content;
	struct s_list	*next;
}				t_list;

typedef struct	s_coord
{
	int				x;
	int				y;
	int				x_i;
	int				y_i;
	struct s_coord	*next;
}				t_coord;

typedef struct	s_env
{
	int			fd;
	char		*data;
	char		**value;
	int			len;
	int			height;
	t_list		*list;
	void		*mlx;
	void		*win;
	t_coord		*ptr;
	int			x;
	int			y;
	int			width;
}				t_env;

void			addnode(t_list **list, char **name);
void			initialise_mlx(void **mlx, void **win);
void			initialise_win(void *mlx, void **win);
int				compute_coord(t_env *e);
void			save_xy(t_coord **ptr, t_env *e, int z);
void			draw_line(t_vect point1, t_vect point2, t_env *e);
void			draw_rows(t_env *e);
t_vect			find_below(t_coord *ptr);
void			draw_columns(t_env *e);
void			draw_verticle(t_vect point1, t_vect point2, t_env *e);

#endif
