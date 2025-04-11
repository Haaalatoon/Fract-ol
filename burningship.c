/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 04:30:22 by hrhilane          #+#    #+#             */
/*   Updated: 2025/04/10 04:30:24 by hrhilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static double	burn_divergence(double x, double y, int max_iter)
{
	int		i;
	double	tmp;
	double	real;
	double	imaginary;

	i = 0;
	real = x;
	imaginary = y;
	while (i < max_iter)
	{
		tmp = real;
		real = real * real - imaginary * imaginary + x;
		imaginary = 2 * fabs(tmp * imaginary) + y;
		if (fabs(real) + fabs(imaginary) > 10)
			return (i);
		i++;
	}
	return (0);
}

void	create_img_burning(t_vars *v)
{
	double	i;
	double	j;
	long	zoom;
	int		iterations;
	int		color;

	i = 0;
	zoom = ZOOM * v->zoom;
	while (i++ < WIDTH)
	{
		j = 0;
		while (j++ < HEIGHT)
		{
			iterations = burn_divergence((i - v->xoff) / zoom, (j - v->yoff)
					/ zoom, v->max_iter);
			color = 0x0;
			if (iterations > 0)
				color = (iterations * 0x00051020) + v->color_scheme;
			draw_pixel(&(v->img), i, j, color);
		}
	}
	mlx_put_image_to_window(v->mlx_ptr, v->win, v->img.img, 0, 0);
}
