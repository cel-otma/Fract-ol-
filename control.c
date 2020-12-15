/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 14:13:17 by cel-otma          #+#    #+#             */
/*   Updated: 2019/12/14 14:13:19 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	control(t_fractol *fractol)
{
	mlx_hook(fractol->win_ptr, 4, 0, mouse_press, fractol);
	mlx_hook(fractol->win_ptr, 2, 0, key_press, fractol);
	mlx_hook(fractol->win_ptr, 6, 0, julia_new, fractol);
}

void	ctl(int key, t_fractol *fractol)
{
	if (key == 69)
		fractol->it_max += 5;
	if (key == 78)
	{
		fractol->it_max -= 5;
		if (fractol->it_max < 4)
			fractol->it_max = 4;
	}
	if (key == 1)
		fractol->julia_mouse = fractol->julia_mouse == 0 ? 1 : 0;
	if (key == 49)
		fractol->palette = fractol->palette + 1 > 8 ? 1 : fractol->palette + 1;
}

int		key_press(int key, t_fractol *fractol)
{
	if (key == 53)
		free_exit(&fractol);
	if (key == 123)
		fractol->o_x += 10 / fractol->zoom;
	if (key == 124)
		fractol->o_x -= 10 / fractol->zoom;
	if (key == 126)
		fractol->o_y += 10 / fractol->zoom;
	if (key == 125)
		fractol->o_y -= 10 / fractol->zoom;
	if (key == 1 || key == 49 || key == 78 || key == 69)
		ctl(key, fractol);
	draw(fractol);
	return (0);
}

int		mouse_press(int button, int x, int y, t_fractol *fractol)
{
	if (button == 4)
	{
		fractol->o_x -= (x / (fractol->zoom * 1.3)) - x / fractol->zoom;
		fractol->o_y -= (y / (fractol->zoom * 1.3)) - y / fractol->zoom;
		fractol->zoom *= 1.3;
		fractol->it_max++;
	}
	if (button == 5)
	{
		fractol->o_x -= (x / (fractol->zoom / 1.3)) - x / fractol->zoom;
		fractol->o_y -= (y / (fractol->zoom / 1.3)) - y / fractol->zoom;
		fractol->zoom /= 1.3;
		fractol->it_max--;
		if (fractol->it_max < 4)
			fractol->it_max = 4;
	}
	draw(fractol);
	return (0);
}
