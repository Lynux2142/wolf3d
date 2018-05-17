/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:24:19 by bede-fre          #+#    #+#             */
/*   Updated: 2018/05/17 09:16:19 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		ft_teleport(t_all *all)
{
	int	y;
	int	x;

	if (all->rc.map[TO_MAP(all->p.y)][TO_MAP(all->p.x)] == '3')
	{
		y = -1;
		while (++y < MAPY)
		{
			x = -1;
			while (++x < MAPX)
			{
				if (all->rc.map[y][x] == '4')
				{
					all->p.x = x * (int)BLOCK_SIZE + 32;
					all->p.y = y * (int)BLOCK_SIZE + 32;
				}
			}
		}
	}
}

int				ft_key_funct(int key, t_all *all)
{
	if (key == KEY_H)
		all->rc.f_eye = (all->rc.f_eye == FALSE) ? TRUE : FALSE;
	if (key == KEY_Q)
		all->p.a += TO_RAD(5.0);
	if (key == KEY_E)
		all->p.a -= TO_RAD(5.0);
	if (key == ESC)
		exit(0);
	ft_teleport(all);
	ft_movements(all, key);
	mlx_destroy_image(all->ptr.mlx, all->info.img);
	all->info.img = mlx_new_image(all->ptr.mlx, INFOX, INFOY);
	ft_print_all(&all->info, &all->rc, &all->p, &all->fp);
	mlx_put_image_to_window(all->ptr.mlx, all->ptr.win, all->info.img, 0, 0);
	mlx_put_image_to_window(all->ptr.mlx, all->ptr.win, all->fp.img,
		INFOX + 1, 0);
	return (1);
}
