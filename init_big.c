/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:49:25 by sderet            #+#    #+#             */
/*   Updated: 2018/02/02 17:51:26 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_big(t_bigg *big)
{
	big->zoom = 400;
	big->prec = 50;
	big->px = 0;
	big->py = 0;
	big->jx = 0;
	big->jy = 0;
	big->movej = 0;
	big->fract[0] = &mandelbrot;
	big->fract[1] = &julia;
	big->fract[2] = &burning_ship;
}
