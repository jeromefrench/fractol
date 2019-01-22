/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:44:03 by jchardin          #+#    #+#             */
/*   Updated: 2019/01/22 09:26:48 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_draw_mandelbrot(t_my_win *s_win)
{
	t_my_man	s_man;

	s_man = s_win->s_man;
	ft_calcul_offset_axes(&s_man, s_win);
	s_win->data = mlx_get_data_addr(s_win->img, &(s_win->bits_per_pixel), &(s_win->size_line), &(s_win->endian));
	ft_calcul_mandelbrot(&s_man, s_win);
	mlx_clear_window(s_win->init, s_win->win);
	mlx_put_image_to_window(s_win->init, s_win->win, s_win->img, 0, 0);
	s_win->s_man = s_man;
}

void			ft_calcul_mandelbrot(t_my_man *s_man, t_my_win *s_win)
{
	s_man->n = 0;
	s_man->y_pixel = 0;
	while (s_man->y_pixel < s_win->height)
	{
		s_man->x_pixel = 0;
		while (s_man->x_pixel < s_win->width)
		{
			s_man->y = ((s_man->y_pixel * (s_man->y_max - s_man->y_min)) / s_win->height) + s_man->y_min;
			s_man->x = ((s_man->x_pixel * (s_man->x_max - s_man->x_min)) / s_win->width) + s_man->x_min;
			s_man->c = ft_make_complex(s_man->x, s_man->y);
			s_man->z = ft_make_complex(0, 0);
			s_man->n = 1;
			ft_calcul_iteration_mandelbrot(s_man, s_win);
			ft_choose_color_and_put_pixel(s_man, s_win);
		}
		s_man->y_pixel++;
	}
}

void			ft_calcul_offset_axes(t_my_man *s_man, t_my_win *s_win)
{
	if ((int)(s_man->zoom * 10) == 5)
	{
		s_man->x_offset = (((s_man->x_mouse * (s_man->x_max - s_man->x_min)) / s_win->width) + s_man->x_min) * s_man->zoom;
		s_man->y_offset = (((s_man->y_mouse * (s_man->y_max - s_man->y_min)) / s_win->height) + s_man->y_min) * s_man->zoom;
		s_man->y_min = s_man->y_min * s_man->zoom;
		s_man->y_max = s_man->y_max * s_man->zoom;
		s_man->x_min = s_man->x_min * s_man->zoom;
		s_man->x_max = s_man->x_max * s_man->zoom;
		s_man->y_min += s_man->y_offset;
		s_man->y_max += s_man->y_offset;
		s_man->x_min += s_man->x_offset;
		s_man->x_max += s_man->x_offset;
	}
}

void			ft_calcul_iteration_mandelbrot(t_my_man *s_man, t_my_win *s_win)
{
	while ((s_man->n <= s_man->n_max) && (ft_complex_mod(s_man->z) < 4))
	{
		ft_complex_square(&(s_man->z));
		s_man->z = ft_complex_add(s_man->z, s_man->c);
		s_man->n++;
	}
}

void			ft_choose_color_and_put_pixel(t_my_man *s_man, t_my_win *s_win)
{
	if (s_man->n > s_man->n_max)
		s_man->color = 0;
	else
		s_man->color = s_man->n; // 0 -> 255
	ft_put_pixel(s_win->data, (int)s_man->x_pixel, (int)s_man->y_pixel, s_man->color, s_win);
	s_man->x_pixel++;
}
