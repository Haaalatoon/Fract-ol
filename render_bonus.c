/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 04:33:04 by hrhilane          #+#    #+#             */
/*   Updated: 2025/04/10 04:33:05 by hrhilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	draw_selected_fractal_bonus(t_vars *v)
{
	if (v->fractal_type == 0)
		create_img_mandelbrot(v);
	else if (v->fractal_type == 1)
		create_img_julia(v);
	else if (v->fractal_type == 2)
		create_img_burning(v);
	else if (v->fractal_type == 3)
		create_img_tricorn(v);
	else
		exit(write(2, "Error: Invalid fractal type\n", 27));
}

int	change_color(t_vars *v)
{
	// v->color_scheme += 0x000A141A;
	v->color_scheme += 0x0011070D;
	draw_selected_fractal_bonus(v);
	return (0);
}
