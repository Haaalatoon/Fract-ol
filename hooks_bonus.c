/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 04:31:23 by hrhilane          #+#    #+#             */
/*   Updated: 2025/04/10 04:31:25 by hrhilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	mousehook_bonus(int b, int x, int y, t_vars *v)
{
	if (5 == b && MAX_ZOOM - 10 > v->zoom)
	{
		v->xoff += (v->xoff - x);
		v->yoff += (v->yoff - y);
		v->zoom *= 2;
		v->max_iter += 5;
	}
	else if (4 == b && v->zoom > 1)
	{
		v->xoff = (WIDTH / 2) * (v->zoom < 5) + (v->xoff - (v->xoff - x) / 2)
			* (v->zoom >= 5);
		v->yoff = (HEIGHT / 2) * (v->zoom < 5) + (v->yoff - (v->yoff - y) / 2)
			* (v->zoom >= 5);
		v->zoom /= 2;
		v->max_iter -= 5;
	}
	else
		return (0);
	return (draw_selected_fractal_bonus(v), 0);
}

int	keyhook_bonus(int key, t_vars *v)
{
	if (65307 == key)
		return (cleanup_and_exit(v));
	if (key == 99)
	{
		change_color(v);
		return (0);
	}
	if (v->zoom < 2)
		return (0);
	else if (UP == key)
		v->yoff += ZOOM / log2(v->zoom);
	else if (DOWN == key)
		v->yoff -= ZOOM / log2(v->zoom);
	else if (RIGHT == key)
		v->xoff -= ZOOM / log2(v->zoom);
	else if (LEFT == key)
		v->xoff += ZOOM / log2(v->zoom);
	else
		return (0);
	return (draw_selected_fractal_bonus(v), 0);
}
