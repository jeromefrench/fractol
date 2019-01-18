/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_math_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:47:56 by jchardin          #+#    #+#             */
/*   Updated: 2019/01/18 15:47:42 by jchardin         ###   ########.fr       */
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

void			ft_complex_add(t_complex *z1, t_complex *z2)
{
	t_complex	z;

	z1->a += z2->a;
	z1->b += z2->b;
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
