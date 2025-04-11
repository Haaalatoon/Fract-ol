/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 04:32:54 by hrhilane          #+#    #+#             */
/*   Updated: 2025/04/10 04:32:56 by hrhilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	parse_two_arg_fract(char **av, t_vars *v)
{
	if (ft_strncmp(av[1], "m", 2))
		v->fractal_type = 0;
	else
		return (1);
	return (0);
}

void	parse_args(int ac, char **av, t_vars *v, int error)
{
	if (error || ac < 2)
	{
		write(2, "Usage:\n", 8);
		write(2, "  ./fractol m          (Mandelbrot)\n", 37);
		write(2, "  ./fractol j <re> <im> (Julia)\n", 33);
		exit(1);
	}
	if (ac == 4 && ft_strncmp(av[1], "j", 2))
	{
		v->fractal_type = 1;
		v->juliax = ft_atof(av[2]);
		v->juliay = ft_atof(av[3]);
		return ;
	}
	else if (ac == 2 && !parse_two_arg_fract(av, v))
		return ;
	parse_args(0, NULL, v, 1);
}
