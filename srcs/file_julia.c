/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:33:39 by jchardin          #+#    #+#             */
/*   Updated: 2019/01/24 15:41:04 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_julia(t_my_win *s_win)
{
	printf("julia\n");
	s_win->fractal = julia;
	ft_init_mandelbrot(s_win);
	ft_init_mlx_window(s_win);
	s_win->img = mlx_new_image(s_win->init, s_win->width, s_win->height);
	ft_draw_julia(s_win);
}

void			ft_draw_julia(t_my_win *s_win)
{
	t_my_man	s_man;

	s_man = s_win->s_man;
	ft_calcul_offset_axes(&s_man, s_win);
	s_win->data = mlx_get_data_addr(s_win->img, &(s_win->bits_per_pixel), &(s_win->size_line), &(s_win->endian));
	ft_calcul_julia(&s_man, s_win);
	mlx_clear_window(s_win->init, s_win->win);
	mlx_put_image_to_window(s_win->init, s_win->win, s_win->img, 0, 0);
	s_win->s_man = s_man;
}

void			ft_calcul_julia(t_my_man *s_man, t_my_win *s_win)
{
	printf("julia\n");
	s_man->n = 0;
	s_man->pixel.y = 0;
	while (s_man->pixel.y < s_win->height)
	{
		s_man->pixel.x = 0;
		while (s_man->pixel.x < s_win->width)
		{
			s_man->point.y = ((s_man->pixel.y * (s_man->axes.max.y - s_man->axes.min.y)) / s_win->height) + s_man->axes.min.y;
			s_man->point.x = ((s_man->pixel.x * (s_man->axes.max.x - s_man->axes.min.x)) / s_win->width) + s_man->axes.min.x;
			s_man->c = ft_make_complex(0.285, 0.01);
			s_man->z = ft_make_complex(s_man->point.x, s_man->point.y);
			s_man->n = 1;
			ft_calcul_iteration_mandelbrot(s_man);
			ft_choose_color_and_put_pixel(s_man, s_win);
		}
		s_man->pixel.y++;
	}
}
