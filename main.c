/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:27:51 by sderet            #+#    #+#             */
/*   Updated: 2018/02/13 16:05:10 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>
#include "libft/libft.h"
#include <math.h>

int		std_err(int err)
{
	if (err == 1)
		ft_putendl("usage :	./fractol [mandelbrot | julia | burning_ship]");
	if (err == 2)
		ft_putendl("Error : source file format may be incorrect.");
	return (1);
}

int		keypress(int keycode, t_bigg *big)
{
	if (keycode > 122 && keycode < 127)
	{
		if ((keycode == 126 || keycode == 125) && (big->py < 2147483560))
			big->py += (keycode == 125 ? 80 : -80);
		else if (big->px < 2147483560)
			big->px += (keycode == 124 ? 80 : -80);
	}
	if (keycode == 14 || keycode == 2)
		zoom(keycode, big);
	if (keycode == 32 || keycode == 34)
	{
		big->prec += (keycode == 32 ? -15 : 15);
		big->prec = (big->prec < 20 ? 20 : big->prec - 1 + 1);
	}
	if (keycode == 15)
		init_big(big);
	if (keycode == 38)
		big->movej = (big->movej == 0 ? 1 : 0);
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	big->fract[big->index](&(big->img), *big);
	mlx_put_image_to_window(big->mlx.mlx, big->mlx.win, big->mlx.image, 0, 0);
	mlx_loop(big->mlx.mlx);
	return (0);
}

int		mousepress(int button, int x, int y, t_bigg *big)
{
	double zoom;

	zoom = 1.1;
	if ((big->px <= 1900000000 && big->py <= 1900000000 &&
			big->zoom <= 1900000000) && (button == 5 || button == 4))
	{
		big->py *= (button == 4 ? zoom : (1 / zoom));
		big->px *= (button == 4 ? zoom : (1 / zoom));
		big->px += (button == 4 ? 1 : -1) * (x / 10);
		big->py += (button == 4 ? 1 : -1) * (y / 10);
		big->zoom *= (button == 4 ? zoom : (1 / zoom));
		big->zoom = (big->zoom < 1 ? 1 : big->zoom - 1 + 1);
	}
	else if (button == 5)
	{
		big->py *= 1 / zoom;
		big->px *= 1 / zoom;
		big->zoom *= 1 / zoom;
	}
	big->fract[big->index](&(big->img), *big);
	mlx_put_image_to_window(big->mlx.mlx, big->mlx.win, big->mlx.image, 0, 0);
	mlx_loop(big->mlx.mlx);
	return (0);
}

int		mousemove(int x, int y, t_bigg *big)
{
	if (big->movej == 0 && big->index == 1)
	{
		big->jx = ((double)x / (double)big->zoom) - 2.1;
		big->jy = ((double)y / (double)big->zoom) - 1.2;
		big->fract[big->index](&(big->img), *big);
		mlx_put_image_to_window(big->mlx.mlx,
				big->mlx.win, big->mlx.image, 0, 0);
		mlx_loop(big->mlx.mlx);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_bigg	big;

	if (argc != 2)
		return (std_err(1));
	if (ft_strcmp(ft_strlow(argv[1]), "mandelbrot") == 0)
		big.index = 0;
	else if (ft_strcmp(ft_strlow(argv[1]), "julia") == 0)
		big.index = 1;
	else if (ft_strcmp(ft_strlow(argv[1]), "burning_ship") == 0)
		big.index = 2;
	else
		return (std_err(1));
	ft_putendl("u : diminue la precision.\ni : augmente la precision.");
	ft_putendl("e : zoom.\nd : dezoom.\nr : reset.\nj : fixe julia.");
	init_big(&big);
	big.mlx.mlx = mlx_init();
	window_creation(&(big.img), &(big.mlx));
	big.fract[big.index](&(big.img), big);
	mlx_put_image_to_window(big.mlx.mlx, big.mlx.win, big.mlx.image, 0, 0);
	mlx_key_hook(big.mlx.win, &keypress, &big);
	mlx_mouse_hook(big.mlx.win, &mousepress, &big);
	mlx_hook(big.mlx.win, 6, 0, mousemove, &big);
	mlx_loop(big.mlx.mlx);
	return (0);
}
