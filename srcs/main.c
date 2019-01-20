/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:45:13 by jchardin          #+#    #+#             */
/*   Updated: 2019/01/19 14:00:28 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(void)
{
	t_complex	z1;
	t_complex	z2;
	t_my_win		s_win;

	ft_init_mlx_window(&s_win);



	s_win.img = mlx_new_image(s_win.init, s_win.width, s_win.height);
	s_win.data = mlx_get_data_addr(s_win.img, &(s_win.bits_per_pixel), &(s_win.size_line), &(s_win.endian));


	//s_win.x = 10;
	//s_win.y = 10;
	//s_win.color = 1;



	ft_draw_mandelbrot(&s_win);


	mlx_put_image_to_window(s_win.init, s_win.win, s_win.img, 0, 0);


	mlx_hook(s_win.win, 2, 0, ft_key_hook, &s_win);
	mlx_loop(s_win.init);
	return (1);
}
