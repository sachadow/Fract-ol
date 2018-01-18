/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:04:17 by sderet            #+#    #+#             */
/*   Updated: 2018/01/18 16:27:24 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void mandelbrot(t_image *img, int zoom)
{
	int			a;
	double		tmp;
	t_pos		pos;
	t_imaginary	im;

	pos.y = 0;
	pos.precis = 100;
	while (pos.y < img->maxy)
	{
		pos.x = 0;
		while (pos.x < img->maxx)
		{
			im.cx = pos.x / zoom + (-2.1 + 1.07);
			im.cy = pos.y / zoom + (-1.2 + 0.91);
			im.zx = 0;
			im.zy = 0;
			a = 0;
			while (a < pos.precis && (im.zx * im.zx) + (im.zy * im.zy) < 4)
			{
				tmp = im.zx;
				im.zx = (im.zx * im.zx) - (im.zy * im.zy) + im.cx;
				im.zy = 2 * tmp * im.zy + im.cy;
				a++;
			}
			print_pixelc(img, &pos, a);
			pos.x++;
		}
		pos.y++;
	}
}
