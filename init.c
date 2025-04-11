/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 04:31:44 by hrhilane          #+#    #+#             */
/*   Updated: 2025/04/10 04:31:46 by hrhilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_fractol(t_vars *v)
{
	v->mlx_ptr = mlx_init();
	if (!v->mlx_ptr)
		return (1);
	v->win = mlx_new_window(v->mlx_ptr, WIDTH, HEIGHT, "fractol");
	if (!v->win)
		return (1);
	v->img.img = mlx_new_image(v->mlx_ptr, WIDTH, HEIGHT);
	if (!v->img.img)
	{
		mlx_destroy_window(v->mlx_ptr, v->win);
		mlx_destroy_display(v->mlx_ptr);
		return (1);
	}
	v->img.addr = mlx_get_data_addr(v->img.img, &(v->img.bpp),
			&(v->img.line_len), &(v->img.endian));
	v->xoff = WIDTH / 2;
	v->yoff = HEIGHT / 2;
	v->zoom = 2;
	v->max_iter = MAX_ITER;
	v->color_scheme =  0;
	return (0);
}
