/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:45:13 by jchardin          #+#    #+#             */
/*   Updated: 2019/01/23 15:44:42 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				ft_pointer(int button, int x, int y, t_my_win *s_win)
{
	printf("button =%d\n", button);
	s_win->s_man.zoom = 0.5;
	s_win->s_man.mouse.x = x;
	s_win->s_man.mouse.y = y;
	ft_draw_mandelbrot(s_win);
	return (1);
}

int				main(int argc, char **argv)
{
	t_complex	z1;
	t_complex	z2;
	t_my_win	s_win;

	ft_init_param_menu(&s_win);
	ft_choose_fractol(&s_win, argc, argv);
	mlx_hook(s_win.win, 2, 0, ft_key_hook, &s_win);
	mlx_hook(s_win.win, 4, 0, ft_pointer, &s_win);
	mlx_loop(s_win.init);
	return (1);
}
