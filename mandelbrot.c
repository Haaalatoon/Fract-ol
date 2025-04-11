/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 04:32:44 by hrhilane          #+#    #+#             */
/*   Updated: 2025/04/10 04:32:45 by hrhilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	mandel_divergence(double x, double y, int max_iter)
{
	int		i;
	double	tmp;
	double	real;
	double	imaginary;

	i = 0;
	real = 0;
	imaginary = 0;
	while (i < max_iter)
	{
		tmp = real;
		real = real * real - (imaginary * imaginary) + x;
		imaginary = 2 * tmp * imaginary + y;
		// if (fabs(real) + fabs(imaginary) > 10)
		if (real * real + imaginary * imaginary > 10)
			return (i);
		i++;
	}
	return (0);
}

void	create_img_mandelbrot(t_vars *v)
{
	double	x_pix;
	double	y_pix;
	long	zoom;
	int		iterations;
	int		color;

	x_pix = 0;
	zoom = ZOOM * v->zoom;
	while (x_pix++ < WIDTH)
	{
		y_pix = 0;
		while (y_pix++ < HEIGHT)
		{
			iterations = mandel_divergence((x_pix - v->xoff) / zoom, (y_pix
						- v->yoff) / zoom, v->max_iter);
			color = 0x0;
			if (iterations > 0)
				// color = (iterations * 0x00051020) + v->color_scheme;
				color = (iterations * iterations) * 0x00010204 + v->color_scheme;
			draw_pixel(&(v->img), x_pix, y_pix, color);
		}
	}
	mlx_put_image_to_window(v->mlx_ptr, v->win, v->img.img, 0, 0);
}
