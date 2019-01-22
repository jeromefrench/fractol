/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:45:13 by jchardin          #+#    #+#             */
/*   Updated: 2019/01/22 19:09:27 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_init_param_menu(t_my_win *s_win)
{
	s_win->valid_param = ft_strdup("List of valid param:\nMandelbrot\nJulia\nburning ship");
	s_win->listparam = (char**)malloc(sizeof(char*) * 3);
	s_win->listparam[0] = ft_strdup("mandelbrot");
	s_win->listparam[1] = ft_strdup("julia");
	s_win->listparam[2] = ft_strdup("burning ship");
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

void		ft_quit(char *str)
{
	ft_putstr(str);
	ft_putstr("\n");
	exit(0);
}

int				main(int argc, char **argv)
{
	t_complex	z1;
	t_complex	z2;
	t_my_win	s_win;

	ft_init_param_menu(&s_win);
	(void)argv;
	if (argc != 2)
		ft_quit(s_win.valid_param);
	else if (ft_strcmp(argv[1], s_win.listparam[MANDELBROT]) == 0) 
		ft_mandelbrot(&s_win);
	else if (ft_strcmp(argv[1], s_win.listparam[JULIA]) == 0) 
		ft_julia(&s_win);
	else if (ft_strcmp(argv[1], s_win.listparam[BURNIG_SHIP]) == 0) 
		ft_burning_ship(&s_win);
	else
		ft_quit("error in param");

	mlx_hook(s_win.win, 2, 0, ft_key_hook, &s_win);
	mlx_hook(s_win.win, 4, 0, ft_pointer, &s_win);
	mlx_loop(s_win.init);
	return (1);
}
