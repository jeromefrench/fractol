/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:30:02 by jchardin          #+#    #+#             */
/*   Updated: 2019/01/23 15:58:36 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_init_param_menu(t_my_win *s_win)
{
	s_win->valid_param =
ft_strdup("List of valid param:\nMandelbrot\nJulia\nburning ship");
	s_win->listparam = (char**)malloc(sizeof(char*) * 3);
	s_win->fractal = mandelbrot;
	s_win->listparam[s_win->fractal] = ft_strdup("mandelbrot");
	s_win->fractal = julia;
	s_win->listparam[s_win->fractal] = ft_strdup("julia");
	s_win->fractal = burning_ship;
	s_win->listparam[s_win->fractal] = ft_strdup("burning ship");
}

void			ft_quit(char *str)
{
	ft_putstr(str);
	ft_putstr("\n");
	exit(0);
}

void			ft_choose_fractol(t_my_win *s_win, int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
		ft_quit(s_win->valid_param);
	else if (ft_strcmp(argv[1],
s_win->listparam[s_win->fractal = mandelbrot]) == 0)
		ft_mandelbrot(s_win);
	else if (ft_strcmp(argv[1],
s_win->listparam[s_win->fractal = julia]) == 0)
		ft_julia(s_win);
	else if (ft_strcmp(argv[1],
s_win->listparam[s_win->fractal = burning_ship]) == 0)
		ft_burning_ship(s_win);
	else
		ft_quit("error in param");
}
