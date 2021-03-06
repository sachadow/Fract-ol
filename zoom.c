/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 18:03:30 by sderet            #+#    #+#             */
/*   Updated: 2018/02/02 18:04:50 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int keycode, t_bigg *big)
{
	if (big->px <= 1900000000 && big->py <= 1900000000 &&
			big->zoom <= 1900000000)
	{
		big->py *= (keycode == 14 ? 1.1 : (1 / 1.1));
		big->px *= (keycode == 14 ? 1.1 : (1 / 1.1));
		big->zoom *= (keycode == 14 ? 1.1 : (1 / 1.1));
		big->zoom = (big->zoom < 1 ? 1 : big->zoom - 1 + 1);
	}
	else if (keycode == 2)
	{
		big->py *= 1 / 1.1;
		big->px *= 1 / 1.1;
		big->zoom *= 1 / 1.1;
	}
}
