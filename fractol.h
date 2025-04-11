/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 04:31:13 by hrhilane          #+#    #+#             */
/*   Updated: 2025/04/10 04:31:15 by hrhilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1600
# define HEIGHT 1400
# define ZOOM 200
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define MAX_ITER 100

# define MANDELBROT 0
# define JULIA 1

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_data;

typedef struct s_vars
{
	t_data	img;
	void	*mlx_ptr;
	void	*win;
	double	juliax;
	double	juliay;
	long	zoom;
	int		xoff;
	int		yoff;
	int		max_iter;
	char	fractal_type;
	int		color_scheme;
}			t_vars;

int			init_fractol(t_vars *v);
void		parse_args(int ac, char **av, t_vars *v, int error);
void		draw_pixel(t_data *img, int x, int y, int c);
int			cleanup_and_exit(t_vars *v);
int			ft_strncmp(char *s1, char *s2, size_t n);
double		ft_atof(char *s);
;
int			keyhook_mandatory(int key, t_vars *v);
int			mousehook_mandatory(int button, int x, int y, t_vars *v);
void		draw_selected_fractal_mandatory(t_vars *v);
void		create_img_mandelbrot(t_vars *v);
void		create_img_julia(t_vars *v);

#endif
