/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_calcul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:13:57 by cel-otma          #+#    #+#             */
/*   Updated: 2019/12/14 14:13:59 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_fractol *fractol, int i, int j)
{
	fractol->c_rel = i / fractol->zoom + fractol->o_x;
	fractol->c_img = j / fractol->zoom + fractol->o_y;
	fractol->z_rel = 0;
	fractol->z_img = 0;
	fractol->it = 0;
	while (fractol->z_rel * fractol->z_rel + fractol->z_img *
			fractol->z_img < 4 && fractol->it < fractol->it_max)
	{
		fractol->preview = fractol->z_rel;
		fractol->z_rel = fractol->z_rel * fractol->z_rel -
			fractol->z_img * fractol->z_img + fractol->c_rel;
		fractol->z_img = 2 * fractol->z_img * fractol->preview + fractol->c_img;
		fractol->it++;
	}
	if (fractol->it == fractol->it_max)
		put_pixel(fractol, i, j, 0x000000);
	else
		put_pixel(fractol, i, j, (fractol->color * fractol->it));
}

void	burningship(t_fractol *fractol, int i, int j)
{
	fractol->c_rel = i / fractol->zoom + fractol->o_x;
	fractol->c_img = j / fractol->zoom + fractol->o_y;
	fractol->z_rel = 0;
	fractol->z_img = 0;
	fractol->it = 0;
	while (fractol->z_rel * fractol->z_rel + fractol->z_img *
			fractol->z_img < 4 && fractol->it < fractol->it_max)
	{
		fractol->preview = fractol->z_rel;
		fractol->z_rel = fractol->z_rel * fractol->z_rel -
			fractol->z_img * fractol->z_img + fractol->c_rel;
		fractol->z_img = 2 * __ABS(fractol->z_img *
				fractol->preview) + fractol->c_img;
		fractol->it++;
	}
	if (fractol->it == fractol->it_max)
		put_pixel(fractol, i, j, 0x000000);
	else
		put_pixel(fractol, i, j, (fractol->color * fractol->it));
}

void	julia(t_fractol *fractol, int i, int j)
{
	fractol->z_rel = i / fractol->zoom + fractol->o_x;
	fractol->z_img = j / fractol->zoom + fractol->o_y;
	fractol->it = 0;
	while (fractol->z_rel * fractol->z_rel + fractol->z_img
			* fractol->z_img < 4 && fractol->it < fractol->it_max)
	{
		fractol->preview = fractol->z_rel;
		fractol->z_rel = fractol->z_rel * fractol->z_rel -
			fractol->z_img * fractol->z_img + fractol->c_rel;
		fractol->z_img = 2 * fractol->z_img * fractol->preview + fractol->c_img;
		fractol->it++;
	}
	if (fractol->it == fractol->it_max)
		put_pixel(fractol, i, j, 0x000000);
	else
		put_pixel(fractol, i, j, (fractol->color * fractol->it));
}

int		julia_new(int x, int y, t_fractol *fractol)
{
	if (fractol->julia_mouse == 1)
	{
		fractol->c_rel = x / fractol->zoom;
		fractol->c_img = y / fractol->zoom;
		draw(fractol);
	}
	return (0);
}
