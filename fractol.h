/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_head.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:36:53 by sderet            #+#    #+#             */
/*   Updated: 2018/02/05 17:28:08 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>

# define ABS(x) ((x) > 0 ? x : -(x))

typedef struct	s_image
{
	char	*map;
	int		line_len;
	int		bpp;
	int		t_len;
	int		endian;
	int		maxx;
	int		maxy;
}				t_image;

typedef struct	s_mmlx
{
	void *mlx;
	void *win;
	void *image;
}				t_mmlx;

typedef struct	s_imaginary
{
	double cx;
	double cy;
	double zx;
	double zy;
}				t_imaginary;

typedef struct	s_pos
{
	double x;
	double y;
}				t_pos;

typedef struct	s_bigg
{
	t_image	img;
	t_mmlx	mlx;
	char	*name;
	int		zoom;
	int		prec;
	double	px;
	double	py;
	double	jx;
	double	jy;
	int		movej;
	int		index;
	void	(*fract[3])(t_image *, struct s_bigg);
}				t_bigg;

void			init_big(t_bigg *big);

void			zoom(int keycode, t_bigg *big);

/*
**	Prints one pixel on pos in img. Colors are determined by
**	the first 3 ints in col. They are, in order, Blue Green and
**	Red. They range from 0 to 255.
*/
void			print_pixel(t_image *img, t_pos *pos, int *col);

/*
**	Prints one pixel on pos in img. Color is based on
**	different settings, in order to make a good looking
**	fractol.
*/
void			print_pixelc(t_image *img, t_pos *pos, int nb_iter, int precis);

/*
**	Self-explanatory. Prints the mandelbrot fractal on img.
**	Precis indicates the precision of the fractal and zoom
**	indicates the level of zoom. px and py are used in
**	moving the fractal.
*/
void			mandelbrot(t_image *img, t_bigg big);

void			julia(t_image *img, t_bigg big);

void			burning_ship(t_image *img, t_bigg big);

/*
**	Creates the image img.
*/
void			window_creation(t_image *img, t_mmlx *mlx);

#endif
