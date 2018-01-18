/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:04:17 by sderet            #+#    #+#             */
/*   Updated: 2018/01/18 17:52:11 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void mandelbrot(t_image *img, int zoom, int precis, double px, double py)
{
	int			a;
	double		tmp;
	t_pos		pos;
	t_imaginary	im;

	pos.y = 0;
	while (pos.y < img->maxy)
	{
		pos.x = 0;
		while (pos.x < img->maxx)
		{
			im.cx = pos.x / zoom + (-2.1 + px / zoom);
			im.cy = pos.y / zoom + (-1.2 + py / zoom);
			im.zx = 0;
			im.zy = 0;
			a = 0;
			while (a < precis && (im.zx * im.zx) + (im.zy * im.zy) < 4)
			{
				tmp = im.zx;
				im.zx = (im.zx * im.zx) - (im.zy * im.zy) + im.cx;
				im.zy = 2 * tmp * im.zy + im.cy;
				a++;
			}
			print_pixelc(img, &pos, a, precis);
			pos.x++;
		}
		pos.y++;
	}
}
