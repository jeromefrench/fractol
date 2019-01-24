/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_mandelbrot_seconde.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:19:10 by jchardin          #+#    #+#             */
/*   Updated: 2019/01/24 15:11:26 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_calcul_iteration_mandelbrot(t_my_man *s_man)
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
		s_man->color.h = 0;
	else
		s_man->color.h = s_man->n;
	ft_put_pixel(s_win->data, s_man->pixel, s_man->color, s_win);
	s_man->pixel.x++;
}
