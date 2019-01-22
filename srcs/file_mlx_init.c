/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_mlx_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:11:44 by jchardin          #+#    #+#             */
/*   Updated: 2019/01/22 16:25:01 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_init_mlx_window(t_my_win *s_win)
{
	s_win->init = mlx_init();
	s_win->width = 900;
	s_win->height = 600;
	s_win->win = mlx_new_window(s_win->init, s_win->width, s_win->height, "Fractol 42");
}

int				ft_key_hook(int key, t_my_win *s_win)
{
	return (1);
}

char			*ft_put_pixel(char *data, int x, int y,
int color, t_my_win *s_win)
{
	int		size_screen;
	int		pixel;

	int		h;

	h = 360 * color / 255;


	if (h < 121)
	{
		s_win->blue = 0;
		s_win->green = h * 255 /120;
		s_win->red = 255 - s_win->green;
	}
	else if (h < 241)
	{
		s_win->red = 0;
		s_win->blue = (h - 120) * 255 / 120;
		s_win->green = 255 - s_win->blue;
	}
	else
	{
		s_win->green = 0;
		s_win->red = (h - 240) * 255 / 120;
		s_win->blue = 255 - s_win->red;
	}

	s_win->alpha = 0;
	pixel = (y * s_win->width) + x;
	size_screen = (s_win->width * s_win->height);
	if (pixel < size_screen && pixel > 0)
	{
		pixel = pixel * 4;
		data[pixel] = s_win->blue;
		data[pixel + 1] = s_win->green;
		data[pixel + 2] = s_win->red;
		data[pixel + 3] = s_win->alpha;
	}
	return (data);
}
