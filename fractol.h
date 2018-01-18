/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_head.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:36:53 by sderet            #+#    #+#             */
/*   Updated: 2018/01/18 15:51:40 by sderet           ###   ########.fr       */
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
	int precis;
}				t_pos;

typedef struct	s_bigg
{
	t_image	img;
	t_mmlx	mlx;
	int		zoom;
}				t_bigg;

void			print_pixel(t_image *img, t_pos *pos, int *col);

void			print_pixelc(t_image *img, t_pos *pos, int nb_iter);

void			mandelbrot(t_image *img, int zoom);

void			window_creation(t_image *img, t_mmlx *mlx);

int				get_err(t_pos ***pos);

void			print_line(t_image *image, t_pos pos1, t_pos pos);

#endif
