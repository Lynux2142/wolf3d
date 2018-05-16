/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:24:19 by bede-fre          #+#    #+#             */
/*   Updated: 2018/05/16 11:32:56 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		ft_moving_forward(t_all *all)
{
	t_coord		p;
	t_fcoord	sh;

	sh.x = (cos(all->p.a) >= 0) ? HIT_BOX : -HIT_BOX;
	sh.y = (sin(all->p.a) >= 0) ? -HIT_BOX : HIT_BOX;
	p.x = (sh.x + all->p.x + (cos(all->p.a) * SPEED));
	p.y = (sh.y + all->p.y - (sin(all->p.a) * SPEED));
	all->p.x += (all->p.y >= 0.0 && TO_MAP(all->p.y) < 32)
		&& (p.x >= HIT_BOX && p.x < (MAPX * (int)BLOCK_SIZE - HIT_BOX))
		&& (all->rc.map[TO_MAP(all->p.y)][TO_MAP(p.x)] != '1') ?
		(cos(all->p.a) * SPEED) : 0.0;
	all->p.y -= (all->p.x >= 0.0 && TO_MAP(all->p.x) < 32)
		&& (p.y >= HIT_BOX && p.y < (MAPY * (int)BLOCK_SIZE - HIT_BOX))
		&& (all->rc.map[TO_MAP(p.y)][TO_MAP(all->p.x)] != '1') ?
		(sin(all->p.a) * SPEED) : 0.0;
}

static void		ft_moving_backward(t_all *all)
{
	t_coord		p;
	t_fcoord	sh;

	sh.x = (cos(all->p.a) >= 0) ? -HIT_BOX : HIT_BOX;
	sh.y = (sin(all->p.a) >= 0) ? HIT_BOX : -HIT_BOX;
	p.x = (sh.x + all->p.x - (cos(all->p.a) * SPEED));
	p.y = (sh.y + all->p.y + (sin(all->p.a) * SPEED));
	all->p.x -= (all->p.y >= 0.0 && TO_MAP(all->p.y) < 32)
		&& (p.x >= HIT_BOX && p.x < (MAPX * (int)BLOCK_SIZE - HIT_BOX))
		&& (all->rc.map[TO_MAP(all->p.y)][TO_MAP(p.x)] != '1') ?
		(cos(all->p.a) * SPEED) : 0.0;
	all->p.y += (all->p.x >= 0.0 && TO_MAP(all->p.x) < 32)
		&& (p.y >= HIT_BOX && p.y < (MAPX * (int)BLOCK_SIZE - HIT_BOX))
		&& (all->rc.map[TO_MAP(p.y)][TO_MAP(all->p.x)] != '1') ?
		(sin(all->p.a) * SPEED) : 0.0;
}

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
	if (key == 49)
		printf("x: %f\ny: %f\na: %f\n\n", all->p.x, all->p.y, TO_DEG(all->p.a));
	if (key == KEY_H)
		all->rc.f_eye = (all->rc.f_eye == FALSE) ? TRUE : FALSE;
	if (key == KEY_A)
		all->p.a += TO_RAD(5.0);
	if (key == KEY_D)
		all->p.a -= TO_RAD(5.0);
	if (key == KEY_W)
		ft_moving_forward(all);
	if (key == KEY_S)
		ft_moving_backward(all);
	if (key == ESC)
		exit(0);
	ft_teleport(all);
	mlx_destroy_image(all->ptr.mlx, all->info.img);
	all->info.img = mlx_new_image(all->ptr.mlx, INFOX, INFOY);
	ft_print_all(&all->info, &all->rc, &all->p, &all->fp);
	mlx_put_image_to_window(all->ptr.mlx, all->ptr.win, all->info.img, 0, 0);
	mlx_put_image_to_window(all->ptr.mlx, all->ptr.win, all->fp.img,
			INFOX + 1, 0);
	return (1);
}
