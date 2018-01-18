/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_fun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:11:13 by sderet            #+#    #+#             */
/*   Updated: 2018/01/18 17:10:11 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_pixel(t_image *img, t_pos *pos, int *col)
{
	int		a;

	a = 0;
	while (a < 3)
	{
		img->map[(((int)pos->x * 4) + a) +
			((int)pos->y * img->line_len)] = (char)col[a];
		a++;
	}
	img->map[(((int)pos->x * 4) + a) +
		((int)pos->y * img->line_len)] = (char)0;
}

void	print_pixelc(t_image *img, t_pos *pos, int nb_iter, int precis)
{
	int colo[3];
	int a;

	a = -1;
	colo[0] = 255;
	colo[1] = 255;
	colo[2] = 0;
	if (nb_iter < precis)
		colo[2] = (1000 * nb_iter * 5) / precis;
	else
		while (++a < 3)
			colo[a] = 0;
	print_pixel(img, pos, colo);
}
