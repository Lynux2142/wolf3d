/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:24:19 by bede-fre          #+#    #+#             */
/*   Updated: 2018/05/02 14:40:05 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		ft_move(int key, t_all *all)
{
	t_coord		p;
	t_fcoord	sh;

	if (key == KEY_W)
	{
		sh.x = (cos(all->p.a) >= 0) ? HIT_BOX : -HIT_BOX;
		sh.y = (sin(all->p.a) >= 0) ? -HIT_BOX : HIT_BOX;
		p.x = TO_MAP((sh.x + all->p.x + (cos(all->p.a) * SPEED)));
		p.y = TO_MAP((sh.y + all->p.y - (sin(all->p.a) * SPEED)));
		all->p.x += (all->rc.map[TO_MAP(all->p.y)][p.x] != '1') ?
			(cos(all->p.a) * SPEED) : 0.0;
		all->p.y -= (all->rc.map[p.y][TO_MAP(all->p.x)] != '1') ?
			(sin(all->p.a) * SPEED) : 0.0;
	}
	if (key == KEY_S)
	{
		sh.x = (cos(all->p.a) >= 0) ? -HIT_BOX : HIT_BOX;
		sh.y = (sin(all->p.a) >= 0) ? HIT_BOX : -HIT_BOX;
		p.x = TO_MAP((sh.x + all->p.x - (cos(all->p.a) * SPEED)));
		p.y = TO_MAP((sh.y + all->p.y + (sin(all->p.a) * SPEED)));
		all->p.x -= (all->rc.map[TO_MAP(all->p.y)][p.x] != '1') ?
			(cos(all->p.a) * SPEED) : 0.0;
		all->p.y += (all->rc.map[p.y][TO_MAP(all->p.x)] != '1') ?
			(sin(all->p.a) * SPEED) : 0.0;
	}
}

int				ft_key_funct(int key, t_all *all)
{
	if (key == KEY_A)
		all->p.a += TO_RAD(2.0);
	if (key == KEY_D)
		all->p.a -= TO_RAD(2.0);
	if (key == KEY_W || key == KEY_S)
		ft_move(key, all);
	if (key == ESC)
		exit(0);
	mlx_destroy_image(all->info.img, all->info.data);
	all->info.img = mlx_new_image(all->ptr.mlx, INFOX, INFOY);
	all->info.data = mlx_get_data_addr(all->info.img,
		&all->info.bpp, &all->info.sl, &all->info.endian);
	ft_print_all(&all->info, &all->rc, &all->p, &all->fp);
	mlx_put_image_to_window(all->ptr.mlx, all->ptr.win, all->info.img, 0, 0);
	mlx_put_image_to_window(all->ptr.mlx, all->ptr.win, all->fp.img,
		INFOX + 1, 0);
	return (1);
}
