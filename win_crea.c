/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_crea.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:05:17 by sderet            #+#    #+#             */
/*   Updated: 2018/01/16 18:02:18 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx/mlx.h"
#include <stdlib.h>
#include <fcntl.h>

void	window_creation(t_image *img, t_mmlx *mlx)
{
	img->maxx = 1500;
	img->maxy = 1000;
	mlx->win = mlx_new_window(mlx->mlx, img->maxx, img->maxy, "Fractol");
	mlx->image = mlx_new_image(mlx->mlx, img->maxx, img->maxy);
	img->map = mlx_get_data_addr(mlx->image,
			&img->bpp, &img->line_len, &img->endian);
}
