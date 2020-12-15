/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:12:56 by cel-otma          #+#    #+#             */
/*   Updated: 2019/12/14 14:12:58 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_fractol *fractol, int x, int y, int color)
{
	if (x < 800 && x >= 0 && y >= 0 && y < 800)
		fractol->data[x + y * 800] = color;
}

void	draw(t_fractol *fractol)
{
	int i;
	int j;

	fractol->color = get_color(fractol->palette);
	i = 0;
	while (i < 800)
	{
		j = 0;
		while (j < 800)
		{
			fractol->funk_ptr(fractol, i, j);
			j++;
		}
		i++;
	}
	mlx_clear_window(fractol->mlx_ptr, fractol->win_ptr);
	mlx_put_image_to_window(fractol->mlx_ptr,\
			fractol->win_ptr, fractol->img_ptr, 0, 0);
}
