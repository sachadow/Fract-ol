/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_head.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:36:53 by sderet            #+#    #+#             */
/*   Updated: 2018/01/18 17:51:44 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_HEAD_H
# define FDF_HEAD_H

# include "libft/libft.h"
# include "minilibx/mlx.h"

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
	int		zoom;
	int		prec;
	double	px;
	double	py;
}				t_bigg;

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
void			mandelbrot(t_image *img, int zoom, int precis, double px, double py);

/*
**	Creates the image img.
*/
void			window_creation(t_image *img, t_mmlx *mlx);

#endif
