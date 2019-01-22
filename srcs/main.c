/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:45:13 by jchardin          #+#    #+#             */
/*   Updated: 2019/01/22 16:33:44 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_init_mandelbrot(t_my_win *s_win)
{
	s_win->s_man.zoom = 1;
	s_win->s_man.n_max = 200;
	s_win->s_man.y_min = -20;
	s_win->s_man.y_max = 20;
	s_win->s_man.x_min = -20;
	s_win->s_man.x_max = 20;
}

int				ft_pointer(int button, int x, int y, t_my_win *s_win)
{
	printf("button =%d\n", button);
	s_win->s_man.zoom = 0.5;
	s_win->s_man.x_mouse = x;
	s_win->s_man.y_mouse = y;
	ft_draw_mandelbrot(s_win);
	return (1);
}

int				main(void)
{
	t_complex	z1;
	t_complex	z2;
	t_my_win	s_win;

	ft_init_mandelbrot(&s_win);
	ft_init_mlx_window(&s_win);
	s_win.img = mlx_new_image(s_win.init, s_win.width, s_win.height);
	ft_draw_mandelbrot(&s_win);
	mlx_hook(s_win.win, 2, 0, ft_key_hook, &s_win);
	mlx_hook(s_win.win, 4, 0, ft_pointer, &s_win);
	mlx_loop(s_win.init);
	return (1);
}
