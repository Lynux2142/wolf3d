/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:24:19 by bede-fre          #+#    #+#             */
/*   Updated: 2018/05/22 13:09:31 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_strafing_left(t_all *all)
{
	t_coord		p;
	t_fcoord	sh;

	sh.x = (sin(all->p.a) >= 0) ? -HIT_BOX : HIT_BOX;
	sh.y = (cos(all->p.a) >= 0) ? -HIT_BOX : HIT_BOX;
	p.x = (sh.x + all->p.x - (sin(all->p.a) * SPEED));
	p.y = (sh.y + all->p.y - (cos(all->p.a) * SPEED));
	all->p.x -= (all->p.y >= 0.0 && TO_MAP(all->p.y) < 32)
		&& (p.x >= HIT_BOX && p.x < (MAPX * (int)BLOCK_SIZE - HIT_BOX))
		&& (all->rc.map[TO_MAP((all->p.y - HIT_BOX))][TO_MAP(p.x)] != '1' &&
		all->rc.map[TO_MAP((all->p.y + HIT_BOX))][TO_MAP(p.x)] != '1') ?
		(sin(all->p.a) * SPEED) : 0.0;
	all->p.y -= (all->p.x >= 0.0 && TO_MAP(all->p.x) < 32)
		&& (p.y >= HIT_BOX && p.y < (MAPY * (int)BLOCK_SIZE - HIT_BOX))
		&& (all->rc.map[TO_MAP(p.y)][TO_MAP((all->p.x + HIT_BOX))] != '1' &&
		all->rc.map[TO_MAP(p.y)][TO_MAP((all->p.x - HIT_BOX))] != '1') ?
		(cos(all->p.a) * SPEED) : 0.0;
}

static void	ft_strafing_right(t_all *all)
{
	t_coord		p;
	t_fcoord	sh;

	sh.x = (sin(all->p.a) >= 0) ? HIT_BOX : -HIT_BOX;
	sh.y = (cos(all->p.a) >= 0) ? HIT_BOX : -HIT_BOX;
	p.x = (sh.x + all->p.x + (sin(all->p.a) * SPEED));
	p.y = (sh.y + all->p.y + (cos(all->p.a) * SPEED));
	all->p.x += (all->p.y >= 0.0 && TO_MAP(all->p.y) < 32)
		&& (p.x >= HIT_BOX && p.x < (MAPX * (int)BLOCK_SIZE - HIT_BOX))
		&& (all->rc.map[TO_MAP((all->p.y + HIT_BOX))][TO_MAP(p.x)] != '1' &&
		all->rc.map[TO_MAP((all->p.y - HIT_BOX))][TO_MAP(p.x)] != '1') ?
		(sin(all->p.a) * SPEED) : 0.0;
	all->p.y += (all->p.x >= 0.0 && TO_MAP(all->p.x) < 32)
		&& (p.y >= HIT_BOX && p.y < (MAPX * (int)BLOCK_SIZE - HIT_BOX))
		&& (all->rc.map[TO_MAP(p.y)][TO_MAP((all->p.x + HIT_BOX))] != '1' &&
		all->rc.map[TO_MAP(p.y)][TO_MAP((all->p.x - HIT_BOX))] != '1') ?
		(cos(all->p.a) * SPEED) : 0.0;
}

static void	ft_moving_forward(t_all *all)
{
	t_coord		p;
	t_fcoord	sh;

	sh.x = (cos(all->p.a) >= 0) ? HIT_BOX : -HIT_BOX;
	sh.y = (sin(all->p.a) >= 0) ? -HIT_BOX : HIT_BOX;
	p.x = (sh.x + all->p.x + (cos(all->p.a) * SPEED));
	p.y = (sh.y + all->p.y - (sin(all->p.a) * SPEED));
	all->p.x += (all->p.y >= 0.0 && TO_MAP(all->p.y) < 32)
		&& (p.x >= HIT_BOX && p.x < (MAPX * (int)BLOCK_SIZE - HIT_BOX))
		&& (all->rc.map[TO_MAP((all->p.y - HIT_BOX))][TO_MAP(p.x)] != '1' &&
		all->rc.map[TO_MAP((all->p.y + HIT_BOX))][TO_MAP(p.x)] != '1') ?
		(cos(all->p.a) * SPEED) : 0.0;
	all->p.y -= (all->p.x >= 0.0 && TO_MAP(all->p.x) < 32)
		&& (p.y >= HIT_BOX && p.y < (MAPY * (int)BLOCK_SIZE - HIT_BOX))
		&& (all->rc.map[TO_MAP(p.y)][TO_MAP((all->p.x + HIT_BOX))] != '1' &&
		all->rc.map[TO_MAP(p.y)][TO_MAP((all->p.x - HIT_BOX))] != '1') ?
		(sin(all->p.a) * SPEED) : 0.0;
}

static void	ft_moving_backward(t_all *all)
{
	t_coord		p;
	t_fcoord	sh;

	sh.x = (cos(all->p.a) >= 0) ? -HIT_BOX : HIT_BOX;
	sh.y = (sin(all->p.a) >= 0) ? HIT_BOX : -HIT_BOX;
	p.x = (sh.x + all->p.x - (cos(all->p.a) * SPEED));
	p.y = (sh.y + all->p.y + (sin(all->p.a) * SPEED));
	all->p.x -= (all->p.y >= 0.0 && TO_MAP(all->p.y) < 32)
		&& (p.x >= HIT_BOX && p.x < (MAPX * (int)BLOCK_SIZE - HIT_BOX))
		&& (all->rc.map[TO_MAP((all->p.y - HIT_BOX))][TO_MAP(p.x)] != '1' &&
		all->rc.map[TO_MAP((all->p.y + HIT_BOX))][TO_MAP(p.x)] != '1') ?
		(cos(all->p.a) * SPEED) : 0.0;
	all->p.y += (all->p.x >= 0.0 && TO_MAP(all->p.x) < 32)
		&& (p.y >= HIT_BOX && p.y < (MAPX * (int)BLOCK_SIZE - HIT_BOX))
		&& (all->rc.map[TO_MAP(p.y)][TO_MAP((all->p.x + HIT_BOX))] != '1' &&
		all->rc.map[TO_MAP(p.y)][TO_MAP((all->p.x - HIT_BOX))] != '1') ?
		(sin(all->p.a) * SPEED) : 0.0;
}

int			ft_movements(t_all *all)
{
	if (all->keys_tab[KEY_A] == TRUE)
		ft_strafing_left(all);
	if (all->keys_tab[KEY_D] == TRUE)
		ft_strafing_right(all);
	if (all->keys_tab[KEY_W] == TRUE)
		ft_moving_forward(all);
	if (all->keys_tab[KEY_S] == TRUE)
		ft_moving_backward(all);
	if (all->keys_tab[KEY_Q] == TRUE)
		all->p.a += TO_RAD(2.5);
	if (all->keys_tab[KEY_E] == TRUE)
		all->p.a -= TO_RAD(2.5);
	mlx_destroy_image(all->ptr.mlx, all->info.img);
	all->info.img = mlx_new_image(all->ptr.mlx, INFOX, INFOY);
	ft_print_all(all);
	mlx_put_image_to_window(all->ptr.mlx, all->ptr.win, all->info.img, 0, 0);
	mlx_put_image_to_window(all->ptr.mlx, all->ptr.win, all->fp.img,
		INFOX + 1, 0);
	return (1);
}
