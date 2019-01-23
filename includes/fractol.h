/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:43:13 by jchardin          #+#    #+#             */
/*   Updated: 2019/01/23 15:59:09 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>

typedef enum	e_myfractal
{
	mandelbrot,
	julia,
	burning_ship
}				t_fractal;

typedef struct	s_complex
{
	double		a;
	double		b;
}				t_complex;

typedef struct	s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct	s_axes
{
	t_point		max;
	t_point		min;
}				t_axes;

typedef struct	s_my_man
{
	t_point		pixel;
	t_point		mouse;
	t_point		offset;
	t_complex	z;
	t_complex	c;
	t_axes		axes;
	t_point		point;
	double		n_max;
	double		n;
	double		color;
	double		zoom;
}				t_my_man;

typedef struct	s_my_win
{
	void		*init;
	void		*win;
	void		*img;
	char		*data;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			blue;
	int			green;
	int			red;
	int			alpha;
	int			x;
	int			y;
	int			color;
	t_my_man	s_man;
	char		*valid_param;
	char		**listparam;
	e_fractal	fractal;
}				t_my_win;

t_complex		ft_make_complex(double a, double b);
void			ft_complex_square(t_complex *z);
double			ft_complex_mod(t_complex z);
void			ft_init_mlx_window(t_my_win *s_win);
int				ft_key_hook(int key, t_my_win *s_win);
char			*ft_put_pixel(char *data, int x, int y, int color, t_my_win *s_win);
void			ft_draw_mandelbrot(t_my_win *s_win);
t_complex		ft_complex_add(t_complex z1, t_complex z2);
void			ft_choose_color_and_put_pixel(t_my_man *s_man, t_my_win *s_win);
void			ft_calcul_iteration_mandelbrot(t_my_man *s_man,
t_my_win *s_win);
void			ft_calcul_offset_axes(t_my_man *s_man, t_my_win *s_win);
void			ft_calcul_mandelbrot(t_my_man *s_man, t_my_win *s_win);
void			ft_julia(t_my_win *s_win);
void			ft_mandelbrot(t_my_win *s_win);
void			ft_burning_ship(t_my_win *s_win);
void			ft_choose_fractol(t_my_win *s_win, int argc, char **argv);
void			ft_quit(char *str);
void			ft_init_param_menu(t_my_win *s_win);
#endif
