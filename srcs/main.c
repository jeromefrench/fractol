/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:45:13 by jchardin          #+#    #+#             */
/*   Updated: 2019/01/27 16:16:38 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				main(int argc, char **argv)
{
	t_my_win	s_win;

	ft_init_param_menu(&s_win);
	ft_choose_fractol(&s_win, argc, argv);
	ft_init_fractal(&s_win);
	ft_init_mlx_window(&s_win);
	ft_draw(&s_win);
	mlx_hook(s_win.win, 2, 0, ft_key_hook, &s_win);
	mlx_hook(s_win.win, 4, 0, ft_pointer, &s_win);
	mlx_loop(s_win.init);
	return (1);
}

int				ft_key_hook(int key, t_my_win *s_win)
{
	if (key == KEY_ESCAPE)
		ft_quit("escape press");
	if (key == 126)
	{
		s_win->s_man.n_max += 20;
		ft_draw(s_win);
	}
	return (1);
}

int				ft_pointer(int button, int x, int y, t_my_win *s_win)
{
	printf("=%d\n", button);
	if (button == 5 || button == 1) 
	{
		s_win->s_man.zoom = 0.5;
		s_win->s_man.mouse.x = x;
		s_win->s_man.mouse.y = y;
		ft_draw(s_win);
		s_win->s_man.zoom = 0;
	}
	return (1);
}

void			ft_init_fractal(t_my_win *s_win)
{
	s_win->s_man.zoom = 1;
	s_win->s_man.n_max = 200;
	s_win->s_man.axes.min.y = -20;
	s_win->s_man.axes.max.y = 20;
	s_win->s_man.axes.min.x = -20;
	s_win->s_man.axes.max.x = 20;
}

void			ft_init_mlx_window(t_my_win *s_win)
{
	if (!(s_win->init = mlx_init()))
		ft_quit("init mlx failes");
	s_win->width = 900;
	s_win->height = 600;
	if (!(s_win->win = mlx_new_window(s_win->init, s_win->width,
s_win->height, "Fractol 42")))
		ft_quit("init window failed");
	if (!(s_win->img = mlx_new_image(s_win->init, s_win->width, s_win->height)))
		ft_quit("init image failed");
}
