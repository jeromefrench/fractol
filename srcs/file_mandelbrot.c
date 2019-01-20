/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:44:03 by jchardin          #+#    #+#             */
/*   Updated: 2019/01/19 14:25:30 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_draw_mandelbrot(t_my_win *s_win)
{
	float				x_pixel;
	float				y_pixel;
	float				x;
	float				x_max;
	float				x_min;
	float				y_max;
	float				y_min;
	float				y;
	float				n_max;
	t_complex		z;
	t_complex		c;
	float				n;
	float				color;
	n_max = 255;
	y_min = -1;
	y_max = 1;
	x_min = -1;
	x_max = 1;
	x_pixel = 0;
	y_pixel = 0;
	n = 0;
	while(y_pixel < s_win->height)
	{
		x_pixel = 0;
		while (x_pixel < s_win->width)
		{
			y = ((y_pixel * (y_max - y_min)) / s_win->height) + y_min;
			x = ((x_pixel * (x_max - x_min)) / s_win->width) + x_min;
			printf("le y=%f, le x=%f\n", y_pixel, x_pixel);
			c = ft_make_complex( x, y);
			z = ft_make_complex( 0, 0);
			n = 1;
			while ((n <= n_max) && (ft_complex_mod(z) < 4)) //calcul des iterations
			{
				ft_complex_square(&z);
				//printf(" le z =%f ,%f\n", z.a , z.b);
				z = ft_complex_add(z, c);
				//printf(" le z apres addition=%f ,%f\n", z.a , z.b);
				n++;
				//printf("module de z=%f  et le n=%d", ft_complex_mod(z), n);
			}
			if (n > n_max)
				color = 0;
			else
				color = n; // 0 -> 255
			ft_put_pixel(s_win->data, (int)x_pixel, (int)y_pixel, color, s_win);
			x_pixel++;
		}
		y_pixel++;
	}
}
