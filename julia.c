/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 04:31:51 by hrhilane          #+#    #+#             */
/*   Updated: 2025/04/10 04:31:52 by hrhilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	julia_divergence(double x, double y, t_vars *v)
{
	int		i;
	int		max_iter;
	double	tmp;
	double	real;
	double	imaginary;

	i = 0;
	real = v->juliax;
	imaginary = v->juliay;
	max_iter = v->max_iter;
	while (i < max_iter)
	{
		tmp = x;
		x = x * x - (y * y) + real;
		y = 2 * tmp * y + imaginary;
		if (x * x + y * y > 4)
			return (i);
		i++;
	}
	return (0);
}

void	create_img_julia(t_vars *v)
{
	double	i;
	double	j;
	long	zoom;
	int		iterations;
	int		color;

	i = 0;
	zoom = ZOOM * v->zoom;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			iterations = julia_divergence((i - v->xoff) / zoom, (j
						- v->yoff) / zoom, v);
			color = 0x0;
			if (iterations > 0)
				color = (iterations * 0x00051020) + v->color_scheme;
			draw_pixel(&(v->img), i, j, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(v->mlx_ptr, v->win, v->img.img, 0, 0);
}
