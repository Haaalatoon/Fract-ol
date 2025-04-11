/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mandatory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 04:32:23 by hrhilane          #+#    #+#             */
/*   Updated: 2025/04/10 04:32:25 by hrhilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_vars	v;

	parse_args(ac, av, &v, 0);
	if (init_fractol(&v))
		return (1);
	draw_selected_fractal_mandatory(&v);
	mlx_key_hook(v.win, keyhook_mandatory, &v);
	mlx_mouse_hook(v.win, mousehook_mandatory, &v);
	mlx_hook(v.win, 17, 0, cleanup_and_exit, &v);
	mlx_loop(v.mlx_ptr);
	return (0);
}
