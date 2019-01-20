/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:43:13 by jchardin          #+#    #+#             */
/*   Updated: 2019/01/19 13:58:27 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef fractolh
# define fractolh
# include "mlx.h"
# include <math.h>
# include <stdio.h>

typedef struct 	s_complex
{
	double		a;
	double		b;
}				t_complex;

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
}				t_my_win;

t_complex		ft_make_complex(double a, double b);
void			ft_complex_square(t_complex *z);
double			ft_complex_mod(t_complex z);
void			ft_init_mlx_window(t_my_win *s_win);
int				ft_key_hook(int key, t_my_win *s_win);
char			*ft_put_pixel(char *data, int x, int y, int color, t_my_win *s_win);
void			ft_draw_mandelbrot(t_my_win *s_win);
t_complex		ft_complex_add(t_complex z1, t_complex z2);
#endif
