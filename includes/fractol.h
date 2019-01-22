/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:43:13 by jchardin          #+#    #+#             */
/*   Updated: 2019/01/22 09:24:35 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include <math.h>
# include <stdio.h>

typedef struct	s_complex
{
	double		a;
	double		b;
}				t_complex;

typedef struct	s_my_man
{
	double		x_pixel;
	double		y_pixel;
	double		x;
	double		y;
	double		x_max;
	double		y_max;
	double		x_min;
	double		y_min;
	double		n_max;
	double		n;
	t_complex	z;
	t_complex	c;
	double		color;
	double		zoom;
	double		x_mouse;
	double		y_mouse;
	double		x_offset;
	double		y_offset;
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
void			ft_calcul_iteration_mandelbrot(t_my_man *s_man, t_my_win *s_win);
void			ft_calcul_offset_axes(t_my_man *s_man, t_my_win *s_win);
void			ft_calcul_mandelbrot(t_my_man *s_man, t_my_win *s_win);
#endif
