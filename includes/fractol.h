/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:43:13 by jchardin          #+#    #+#             */
/*   Updated: 2019/01/24 19:26:28 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include <math.h>
# include "libft.h"
# define KEY_ESCAPE 53

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

typedef struct	s_pixel
{
	int			x;
	int			y;
}				t_pixel;

typedef struct	s_axes
{
	t_point		max;
	t_point		min;
}				t_axes;

typedef struct	s_color
{
	int			red;
	int			green;
	int			blue;
	int			alpha;
	int			h;
}				t_color;

typedef struct	s_my_man
{
	t_point		pixel;
	t_point		mouse;
	t_point		offset;
	t_complex	z;
	t_complex	c;
	t_axes		axes;
	t_point		point;
	t_color		color;
	double		n_max;
	double		n;
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
	int			alpha;
	int			x;
	int			y;
	t_my_man	s_man;
	char		*valid_param;
	char		**listparam;
	t_fractal	fractal;
}				t_my_win;

t_complex		ft_make_complex(double a, double b);
void			ft_complex_square(t_complex *z);
double			ft_complex_mod(t_complex z);
void			ft_init_mlx_window(t_my_win *s_win);
int				ft_key_hook(int key, t_my_win *s_win);
void			ft_draw(t_my_win *s_win);
void			ft_put_pixel(char *ptr_data, t_point point, t_color color,
t_my_win *s_win);
t_complex		ft_complex_add(t_complex z1, t_complex z2);
void			ft_choose_color_and_put_pixel(t_my_man *s_man, t_my_win *s_win);
void			ft_calcul_offset_axes(t_my_man *s_man, t_my_win *s_win);
void			ft_calcul_fractal(t_my_man *s_man, t_my_win *s_win);
void			ft_choose_fractol(t_my_win *s_win, int argc, char **argv);
void			ft_quit(char *str);
void			ft_init_param_menu(t_my_win *s_win);
t_color			ft_convert_rgb_hsv(t_color color);
void			ft_calcul_iteration(t_my_man *s_mandt, t_my_win *s_win);
void			ft_init_window(t_my_win *s_win);
void			ft_complex_absolute_value_square(t_complex *z);
void			ft_init_fractal(t_my_win *s_win);
int				ft_pointer(int button, int x, int y, t_my_win *s_win);
#endif
