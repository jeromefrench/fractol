/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_math_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:47:56 by jchardin          #+#    #+#             */
/*   Updated: 2019/01/24 17:16:03 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex		ft_make_complex(double a, double b)
{
	t_complex	z;

	z.a = a;
	z.b = b;
	return (z);
}

t_complex		ft_complex_add(t_complex z1, t_complex z2)
{
	z1.a += z2.a;
	z1.b += z2.b;
	return (z1);
}

void			ft_complex_square(t_complex *z)
{
	double	a;
	double	b;

	a = (z->a * z->a) - (z->b * z->b);
	b = 2 * z->a * z->b;
	z->a = a;
	z->b = b;
}

double			ft_complex_mod(t_complex z)
{
	double		mod;

	mod = (z.a * z.a) + (z.b * z.b);
	return (mod);
}

void		ft_complex_absolute_value_square(t_complex *z)
{
	if (z->a < 0)
		z->a = z->a * -1;
	if (z->b < 0)
		z->b = z->b * -1;
	ft_complex_square(z);
}
