/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_mlx_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:11:44 by jchardin          #+#    #+#             */
/*   Updated: 2019/01/24 15:12:56 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_init_mlx_window(t_my_win *s_win)
{
	s_win->init = mlx_init();
	s_win->width = 900;
	s_win->height = 600;
	s_win->win = mlx_new_window(s_win->init, s_win->width,
s_win->height, "Fractol 42");
}


void			ft_put_pixel(char *ptr_data, t_point point, t_color color, t_my_win *s_win)
{
	int			size_screen;
	t_pixel		pixel;
	int			pixel_data;

	color = ft_convert_rgb_hsv(color);
	pixel.x = (int)point.x;
	pixel.y = (int)point.y;
	pixel_data = (pixel.y * s_win->width) + pixel.x;
	size_screen = (s_win->width * s_win->height);
	if (pixel_data < size_screen && pixel_data > 0)
	{
		pixel_data = pixel_data * 4;
		ptr_data[pixel_data] = color.blue;
		ptr_data[pixel_data + 1] = color.green;
		ptr_data[pixel_data + 2] = color.red;
		ptr_data[pixel_data + 3] = color.alpha;
	}
}

t_color			ft_convert_rgb_hsv(t_color color)
{
	color.h = 360 * color.h / 255;
	if (color.h < 121)
	{
		color.blue = 0;
		color.green = color.h * 255 / 120;
		color.red = 255 - color.green;
	}
	else if (color.h < 241)
	{
		color.red = 0;
		color.blue = (color.h - 120) * 255 / 120;
		color.green = 255 - color.blue;
	}
	else
	{
		color.green = 0;
		color.red = (color.h - 240) * 255 / 120;
		color.blue = 255 - color.red;
	}
	color.alpha = 0;
	return (color);
}
