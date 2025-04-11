/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 04:30:52 by hrhilane          #+#    #+#             */
/*   Updated: 2025/04/10 04:30:54 by hrhilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "fractol.h"

# define MAX_ZOOM 4194304
# define BURNINGSHIP 2
# define TRICORN 3

void	create_img_burning(t_vars *v);
void	create_img_tricorn(t_vars *v);
int		mousehook_bonus(int button, int x, int y, t_vars *v);
int		keyhook_bonus(int key, t_vars *v);
void	draw_selected_fractal_bonus(t_vars *v);
int		change_color(t_vars *v);

#endif
