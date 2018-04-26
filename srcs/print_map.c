/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 11:55:11 by lguiller          #+#    #+#             */
/*   Updated: 2018/04/26 12:45:19 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_fill_pixel(t_mlx *ptr, int x, int y, int col)
{
	if ((y >= 0 && y < WINY) && (x >= 0 && x < WINX))
	{
		if (ptr->endian == 0 && ptr->bpp == (8 * 4))
		{
			((char *)(ptr->data))[((x * 4) + (y * ptr->sizeline))] =
				(char)col;
			((char *)(ptr->data))[((x * 4) + (y * ptr->sizeline)) + 1] =
				(char)(col >> 8);
			((char *)(ptr->data))[((x * 4) + (y * ptr->sizeline)) + 2] =
				(char)(col >> 16);
			((char *)(ptr->data))[((x * 4) + (y * ptr->sizeline)) + 3] =
				0;
		}
	}
}

static int	ft_key_funct(int key, void *x)
{
	(void)x;
	if (key == ESC)
		exit(0);
	return (1);
}

static void	ft_rect(t_mlx *ptr, int x, int y, int c)
{
	t_coord	p1;
	t_coord	p2;
	int		zoom;

	zoom = 8;
	p1.y = (y *= zoom);
	p2.x = (x *= zoom) + zoom;
	p2.y = y + zoom;
	while (p1.y <= p2.y)
	{
		p1.x = x;
		while (p1.x <= p2.x)
		{
			ft_fill_pixel(ptr, p1.x, p1.y,
			(p1.x == x || p1.x == p2.x || p1.y == y || p1.y == p2.y) ? 0 : c);
			++p1.x;
		}
		++p1.y;
	}
}

static void	ft_print_map(t_mlx *ptr, char **map)
{
	int		x;
	int		y;
/*	int		zoom;

	zoom = 8;
	y = -1;
	while (++y < (BUFF_SIZE * zoom))
	{
		x = -1;
		while (++x < (BUFF_SIZE * zoom))
			if (x % zoom == 0 || y % zoom == 0)
				ft_fill_pixel(ptr, y, x, 0xFFFFFF);
	}*/

	y = -1;
	while (++y < BUFF_SIZE)
	{
		x = -1;
		while (++x < BUFF_SIZE)
		{
			if (map[y][x] == '1' || map[y][x] == 's')
				ft_rect(ptr, x, y, (map[y][x] == '1') ? 0xFFFFFF : 0xFF00);
		}
	}
}

void		ft_draw(t_raycast rc, t_ray ray, t_player p)
{
	t_mlx	ptr;

	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, WINX, WINY, "wolf3d");
	ptr.img = mlx_new_image(ptr.mlx, WINX, WINY);
	ptr.data = mlx_get_data_addr(ptr.img, &ptr.bpp, &ptr.sizeline, &ptr.endian);
	ft_print_map(&ptr, rc.map);
	ft_algo(&ptr, ray, p, 0xFF0000);
	mlx_put_image_to_window(ptr.mlx, ptr.win, ptr.img, 0, 0);
	mlx_hook(ptr.win, 2, (1L << 0), ft_key_funct, 0);
	mlx_loop(ptr.mlx);
}
