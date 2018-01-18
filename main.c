/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:27:51 by sderet            #+#    #+#             */
/*   Updated: 2018/01/18 17:54:39 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>
#include "libft/libft.h"

int		std_err(int err)
{
	if (err == 1)
		ft_putendl("usage :	./fdf <source_file>");
	if (err == 2)
		ft_putendl("Error : source file format may be incorrect.");
	return (1);
}

int		keypress(int keycode, t_bigg *big)
{
	ft_putnbr(keycode);
	if (keycode > 122 && keycode < 127)
	{
		if (keycode == 126 || keycode == 125)
			big->py += (keycode == 125 ? 10 : -10);
		else
			big->px += (keycode == 124 ? 10 : -10);
		mandelbrot(&(big->img), big->zoom, big->prec, big->px, big->py);
		mlx_put_image_to_window(big->mlx.mlx, big->mlx.win,
				big->mlx.image, 0, 0);
		mlx_loop(big->mlx.mlx);
	}
	if (keycode == 14 || keycode == 2)
	{
		big->zoom += (keycode == 14 ? big->zoom / 10 : -(big->zoom / 10));
		big->zoom = (big->zoom < 1 ? 1 : big->zoom - 1 + 1);
		mandelbrot(&(big->img), big->zoom, big->prec, big->px, big->py);
		mlx_put_image_to_window(big->mlx.mlx, big->mlx.win,
				big->mlx.image, 0, 0);
		mlx_loop(big->mlx.mlx);
	}
	if (keycode == 32 || keycode == 34)
	{
		big->prec += (keycode == 32 ? -15 : 15);
		big->prec = (big->prec < 20 ? 20 : big->prec - 1 + 1);
		mandelbrot(&(big->img), big->zoom, big->prec, big->px, big->py);
		mlx_put_image_to_window(big->mlx.mlx, big->mlx.win,
				big->mlx.image, 0, 0);
		mlx_loop(big->mlx.mlx);
	}
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int		main(int argc, char **argv)
{
	t_bigg	big;

	if (argc != 2)
		return (std_err(argc != 2 ? 1 : 2));
	argv[1][1] = argv[0][1];
	big.zoom = 400;
	big.prec = 50;
	big.px = 0;
	big.py = 0;
	big.mlx.mlx = mlx_init();
	window_creation(&(big.img), &(big.mlx));
	mandelbrot(&(big.img), big.zoom, big.prec, big.px, big.py);
	mlx_put_image_to_window(big.mlx.mlx, big.mlx.win, big.mlx.image, 0, 0);
	mlx_key_hook(big.mlx.win, &keypress, &big);
	mlx_loop(big.mlx.mlx);
	return (0);
}
