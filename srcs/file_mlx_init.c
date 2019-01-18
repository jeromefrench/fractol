/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_mlx_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:11:44 by jchardin          #+#    #+#             */
/*   Updated: 2019/01/18 16:26:43 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	ft_init_mlx_window(t_my_win *s_win)
{
	s_win->init = mlx_init();
	s_win->width = 900;
	s_win->height = 600;
	s_win->win = mlx_new_window(s_win->init, s_win->width, s_win->height, "Fractol 42");
}

int		ft_key_hook(int key, t_my_win *s_win)
{
	return (1);
}

char			*ft_mafonction(char *param, int pixel,
int color, t_my_win *s_win)
{
	int		size_screen;

	s_win->red = 0xff;
	s_win->green = 0xff;
	s_win->blue = 0xff;
	s_win->alpha = 0;
	size_screen = (s_win->width * s_win->height);
	if (pixel < size_screen && pixel > 0)
	{
		pixel = pixel * 4;
		param[pixel] = s_win->blue;
		param[pixel + 1] = s_win->green;
		param[pixel + 2] = s_win->red;
		param[pixel + 3] = s_win->alpha;
	}
	return (param);
}
