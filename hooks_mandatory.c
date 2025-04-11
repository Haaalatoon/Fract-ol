/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_mandatory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 04:31:33 by hrhilane          #+#    #+#             */
/*   Updated: 2025/04/10 04:31:35 by hrhilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mousehook_mandatory(int button, int x, int y, t_vars *v)
{
	(void)x;
	(void)y;
	if (button == 5)
	{
		v->zoom *= 2;
		v->max_iter += 5;
	}
	else if (button == 4 && v->zoom > 1)
	{
		v->zoom /= 2;
		v->max_iter -= 5;
	}
	else
		return (0);
	draw_selected_fractal_mandatory(v);
	return (0);
}

int	keyhook_mandatory(int key, t_vars *v)
{
	if (65307 == key)
		return (cleanup_and_exit(v));
	if (v->zoom < 2)
		return (0);
	return (draw_selected_fractal_mandatory(v), 0);
}
