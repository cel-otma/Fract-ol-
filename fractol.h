/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:32:20 by cel-otma          #+#    #+#             */
/*   Updated: 2019/12/21 16:00:25 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>

# define __ABS(x) (x > 0 ? x : -x)

typedef struct	s_fractol
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*data;
	int			size_line;
	int			bpp;
	int			endian;
	double		zoom;
	double		o_x;
	double		o_y;
	int			fract;
	int			color;
	int			palette;
	int			it;
	int			it_max;
	double		c_rel;
	double		c_img;
	double		z_rel;
	double		z_img;
	double		preview;
	int			julia_mouse;
	void		(*funk_ptr)(struct	s_fractol *, int, int);
}				t_fractol;

int				get_color(int palette);
int				free_exit(t_fractol **fractol);
int				is_fractol(char *argv);
void			put_pixel(t_fractol *fractol, int x, int y, int color);
void			draw(t_fractol *fractol);
void			control(t_fractol *fractol);
int				key_press(int key, t_fractol *fractol);
int				mouse_press(int button, int x, int y, t_fractol *fractol);
void			julia_init(t_fractol *fractol);
void			init_mandelbrot(t_fractol *fractol);
void			initialize(t_fractol *fractol, char *argv);
void			mandelbrot(t_fractol *fractol, int i, int j);
void			julia(t_fractol *fractol, int i, int j);
void			burningship(t_fractol *fractol, int i, int j);
int				julia_new(int x, int y, t_fractol *fractol);
#endif
