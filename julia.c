/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:04:17 by sderet            #+#    #+#             */
/*   Updated: 2018/02/02 17:39:28 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_image *img, t_bigg big)
{
	int			a;
	double		tmp;
	t_pos		pos;
	t_imaginary	im;

	pos.y = -1;
	while (++pos.y < img->maxy)
	{
		pos.x = -1;
		while (++pos.x < img->maxx)
		{
			im.cx = big.jx;
			im.cy = big.jy;
			im.zx = pos.x / big.zoom + (-2.1 + (big.px / big.zoom));
			im.zy = pos.y / big.zoom + (-1.2 + (big.py / big.zoom));
			a = -1;
			while (++a < big.prec && (im.zx * im.zx) + (im.zy * im.zy) < 4)
			{
				tmp = im.zx;
				im.zx = (im.zx * im.zx) - (im.zy * im.zy) + im.cx;
				im.zy = 2 * tmp * im.zy + im.cy;
			}
			print_pixelc(img, &pos, a, big.prec);
		}
	}
}
