/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 04:32:13 by hrhilane          #+#    #+#             */
/*   Updated: 2025/04/10 04:32:14 by hrhilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	main(int ac, char **av)
{
	t_vars	v;

	parse_args(ac, av, &v, 0);
	if (init_fractol(&v))
		return (1);
	draw_selected_fractal_bonus(&v);
	mlx_key_hook(v.win, keyhook_bonus, &v);
	mlx_mouse_hook(v.win, mousehook_bonus, &v);
	mlx_hook(v.win, 17, 0, cleanup_and_exit, &v);
	mlx_loop(v.mlx_ptr);
	return (0);
}
