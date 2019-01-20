/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:44:03 by jchardin          #+#    #+#             */
/*   Updated: 2019/01/20 19:05:44 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_draw_mandelbrot(t_my_win *s_win)
{
	t_my_man	s_man;
	double		x_offset;
	double		y_offset;

	s_man = s_win->s_man;
	printf("\n\n\naa\n");
	printf("le zoom =%f\n", s_man.zoom);
	if ((int)(s_man.zoom * 10) == 5)
	{
		printf("on zoom\n");
		printf("x offset =%f\n", x_offset);
		printf("y offset =%f\n", y_offset);
		x_offset = (((s_man.x_mouse * (s_man.x_max - s_man.x_min)) / s_win->width) + s_man.x_min) * s_man.zoom;
		y_offset = (((s_man.y_mouse * (s_man.y_max - s_man.y_min)) /s_win->height) + s_man.y_min) * s_man.zoom;

	s_man.y_min = s_man.y_min * s_man.zoom;
	s_man.y_max = s_man.y_max * s_man.zoom;
	s_man.x_min = s_man.x_min * s_man.zoom;
	s_man.x_max = s_man.x_max * s_man.zoom;
		
		s_man.y_min += y_offset;
		s_man.y_max += y_offset;
		s_man.x_min += x_offset;
		s_man.x_max += x_offset;
	}


	printf("x_mouse =%f\n", s_man.x_mouse);
	printf("y_mouse =%f\n", s_man.y_mouse);
	printf("y_min =%f\n", s_man.y_min);
	printf("y_max =%f\n", s_man.y_max);
	printf("x_min =%f\n", s_man.x_min);
	printf("x_max =%f\n", s_man.x_max);

	s_man.n = 0;
	s_man.y_pixel = 0;
	s_win->data = mlx_get_data_addr(s_win->img, &(s_win->bits_per_pixel), &(s_win->size_line), &(s_win->endian));
	while(s_man.y_pixel < s_win->height)
	{
		s_man.x_pixel = 0;
		while (s_man.x_pixel < s_win->width)
		{
			s_man.y = ((s_man.y_pixel * (s_man.y_max - s_man.y_min)) / s_win->height) + s_man.y_min;
			s_man.x = ((s_man.x_pixel * (s_man.x_max - s_man.x_min)) / s_win->width) + s_man.x_min;
			s_man.c = ft_make_complex( s_man.x, s_man.y);
			s_man.z = ft_make_complex( 0, 0);
			s_man.n = 1;
			while ((s_man.n <= s_man.n_max) && (ft_complex_mod(s_man.z) < 4)) //calcul des iterations
			{
				ft_complex_square(&(s_man.z));
				s_man.z = ft_complex_add(s_man.z, s_man.c);
				s_man.n++;
			}
			if (s_man.n > s_man.n_max)
				s_man.color = 0;
			else
				s_man.color = s_man.n; // 0 -> 255
			ft_put_pixel(s_win->data, (int)s_man.x_pixel, (int)s_man.y_pixel, s_man.color, s_win);
			s_man.x_pixel++;
		}
		s_man.y_pixel++;
	}
			//mlx_clear_window(s_win->init, s_win->win);
			mlx_put_image_to_window(s_win->init, s_win->win, s_win->img, 0, 0);
			s_win->s_man = s_man;
}
