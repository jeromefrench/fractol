/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:30:02 by jchardin          #+#    #+#             */
/*   Updated: 2019/01/25 11:20:42 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_init_param_menu(t_my_win *s_win)
{
	if (!(s_win->valid_param =
ft_strdup("List of valid param:\nMandelbrot\nJulia\nburning ship")))
		ft_quit("malloc failed");
	if (!(s_win->listparam = (char**)malloc(sizeof(char*) * 3)))
		ft_quit("malloc failed");
	s_win->fractal = mandelbrot;
	if (!(s_win->listparam[s_win->fractal] = ft_strdup("mandelbrot")))
		ft_quit("malloc failed");
	s_win->fractal = julia;
	if (!(s_win->listparam[s_win->fractal] = ft_strdup("julia")))
		ft_quit("malloc failed");
	s_win->fractal = burning_ship;
	if (!(s_win->listparam[s_win->fractal] = ft_strdup("burning ship")))
		ft_quit("malloc failed");
}

void			ft_quit(char *str)
{
	ft_putstr(str);
	ft_putstr("\n");
	exit(0);
}

void			ft_choose_fractol(t_my_win *s_win, int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
		ft_quit(s_win->valid_param);
	else if (ft_strcmp(argv[1],
s_win->listparam[s_win->fractal = mandelbrot]) == 0)
		s_win->fractal = mandelbrot;
	else if (ft_strcmp(argv[1],
s_win->listparam[s_win->fractal = julia]) == 0)
		s_win->fractal = julia;
	else if (ft_strcmp(argv[1],
s_win->listparam[s_win->fractal = burning_ship]) == 0)
		s_win->fractal = burning_ship;
	else
		ft_quit("error in param");
}

void			ft_put_pixel(char *ptr_data, t_point point,
t_color color, t_my_win *s_win)
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
