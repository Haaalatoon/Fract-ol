/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 04:33:37 by hrhilane          #+#    #+#             */
/*   Updated: 2025/04/10 04:33:40 by hrhilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_pixel(t_data *img, int x, int y, int c)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = c;
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] == s2[i]);
}

static int	skip_space_sign(char *str, int *is_neg)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*is_neg *= -1;
		i++;
	}
	return (i);
}

double	ft_atof(char *str)
{
	int		i;
	double	nb;
	int		is_neg;
	double	div;

	nb = 0;
	div = 0.1;
	is_neg = 1;
	i = skip_space_sign(str, &is_neg);
	while (str[i] && (str[i] >= '0' && str[i] <= '9') && str[i] != '.')
	{
		nb = (nb * 10.0) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = nb + ((str[i] - '0') * div);
		div *= 0.1;
		i++;
	}
	if (str[i] && !(str[i] >= '0' && str[i] <= '9'))
		parse_args(0, NULL, NULL, 1);
	return (nb * is_neg);
}

int	cleanup_and_exit(t_vars *v)
{
	mlx_destroy_window(v->mlx_ptr, v->win);
	mlx_destroy_image(v->mlx_ptr, v->img.img);
	mlx_destroy_display(v->mlx_ptr);
	free(v->mlx_ptr);
	exit(0);
	return (0);
}
