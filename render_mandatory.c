/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mandatory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 04:33:11 by hrhilane          #+#    #+#             */
/*   Updated: 2025/04/10 04:33:13 by hrhilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_selected_fractal_mandatory(t_vars *v)
{
	if (v->fractal_type == 0)
		create_img_mandelbrot(v);
	else if (v->fractal_type == 1)
		create_img_julia(v);
}
