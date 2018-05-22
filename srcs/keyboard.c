/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:24:19 by bede-fre          #+#    #+#             */
/*   Updated: 2018/05/22 13:04:48 by bede-fre         ###   ########.fr       */
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
	all->keys_tab[KEY_A] = (key == KEY_A) ? TRUE : all->keys_tab[KEY_A];
	all->keys_tab[KEY_W] = (key == KEY_W) ? TRUE : all->keys_tab[KEY_W];
	all->keys_tab[KEY_S] = (key == KEY_S) ? TRUE : all->keys_tab[KEY_S];
	all->keys_tab[KEY_D] = (key == KEY_D) ? TRUE : all->keys_tab[KEY_D];
	all->keys_tab[KEY_Q] = (key == KEY_Q) ? TRUE : all->keys_tab[KEY_Q];
	all->keys_tab[KEY_E] = (key == KEY_E) ? TRUE : all->keys_tab[KEY_E];
	if (key == KEY_H)
		all->keys_tab[KEY_H] = (all->keys_tab[KEY_H] == FALSE) ? TRUE : FALSE;
	if (key == ESC)
		exit(0);
	ft_teleport(all);
	mlx_destroy_image(all->ptr.mlx, all->info.img);
	all->info.img = mlx_new_image(all->ptr.mlx, INFOX, INFOY);
	ft_print_all(all);
	mlx_put_image_to_window(all->ptr.mlx, all->ptr.win, all->info.img, 0, 0);
	mlx_put_image_to_window(all->ptr.mlx, all->ptr.win, all->fp.img,
		INFOX + 1, 0);
	return (1);
}
