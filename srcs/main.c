/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:45:13 by jchardin          #+#    #+#             */
/*   Updated: 2019/01/24 16:38:51 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				ft_pointer(int button, int x, int y, t_my_win *s_win)
{
	printf("je zoom\n");
	(void)button;
	s_win->s_man.zoom = 0.5;
	s_win->s_man.mouse.x = x;
	s_win->s_man.mouse.y = y;
	if (s_win->fractal == mandelbrot)
		ft_draw_mandelbrot(s_win);
	if (s_win->fractal == julia)
		ft_draw_julia(s_win);
	if (s_win->fractal == burning_ship)
		ft_draw_burning_ship(s_win);
	s_win->s_man.zoom = 0;
	return (1);
}

int				main(int argc, char **argv)
{
	t_my_win	s_win;

	ft_init_param_menu(&s_win);
	ft_choose_fractol(&s_win, argc, argv);
	mlx_hook(s_win.win, 2, 0, ft_key_hook, &s_win);
	mlx_hook(s_win.win, 4, 0, ft_pointer, &s_win);
	mlx_loop(s_win.init);
	return (1);
}

int				ft_key_hook(int key, t_my_win *s_win)
{
	(void)s_win;
	printf("j'augmente n\n");
	if (key == KEY_ESCAPE)
		ft_quit("escape press");
	if (key == 126)
	{
		s_win->s_man.n_max += 20;
		ft_draw_julia(s_win);
	}
	return (1);
}
