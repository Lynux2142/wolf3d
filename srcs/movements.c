/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:24:19 by bede-fre          #+#    #+#             */
/*   Updated: 2018/05/17 09:15:31 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		ft_strafing_left(t_all *all)
{
	t_coord		p;
	t_fcoord	sh;

	sh.x = (sin(all->p.a) >= 0) ? -HIT_BOX : HIT_BOX;
	sh.y = (cos(all->p.a) >= 0) ? -HIT_BOX : HIT_BOX;
	p.x = (sh.x + all->p.x - (sin(all->p.a) * SPEED));
	p.y = (sh.y + all->p.y - (cos(all->p.a) * SPEED));
	all->p.x -= (all->p.y >= 0.0 && TO_MAP(all->p.y) < 32)
		&& (p.x >= HIT_BOX && p.x < (MAPX * (int)BLOCK_SIZE - HIT_BOX))
		&& (all->rc.map[TO_MAP(all->p.y)][TO_MAP(p.x)] != '1') ?
		(sin(all->p.a) * SPEED) : 0.0;
	all->p.y -= (all->p.x >= 0.0 && TO_MAP(all->p.x) < 32)
		&& (p.y >= HIT_BOX && p.y < (MAPY * (int)BLOCK_SIZE - HIT_BOX))
		&& (all->rc.map[TO_MAP(p.y)][TO_MAP(all->p.x)] != '1') ?
		(cos(all->p.a) * SPEED) : 0.0;
}

static void		ft_strafing_right(t_all *all)
{
	t_coord		p;
	t_fcoord	sh;

	sh.x = (sin(all->p.a) >= 0) ? HIT_BOX : -HIT_BOX;
	sh.y = (cos(all->p.a) >= 0) ? HIT_BOX : -HIT_BOX;
	p.x = (sh.x + all->p.x + (sin(all->p.a) * SPEED));
	p.y = (sh.y + all->p.y + (cos(all->p.a) * SPEED));
	all->p.x += (all->p.y >= 0.0 && TO_MAP(all->p.y) < 32)
		&& (p.x >= HIT_BOX && p.x < (MAPX * (int)BLOCK_SIZE - HIT_BOX))
		&& (all->rc.map[TO_MAP(all->p.y)][TO_MAP(p.x)] != '1') ?
		(sin(all->p.a) * SPEED) : 0.0;
	all->p.y += (all->p.x >= 0.0 && TO_MAP(all->p.x) < 32)
		&& (p.y >= HIT_BOX && p.y < (MAPX * (int)BLOCK_SIZE - HIT_BOX))
		&& (all->rc.map[TO_MAP(p.y)][TO_MAP(all->p.x)] != '1') ?
		(cos(all->p.a) * SPEED) : 0.0;
}

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

void			ft_movements(t_all *all, int key)
{
	if (key == KEY_A)
		ft_strafing_left(all);
	if (key == KEY_D)
		ft_strafing_right(all);
	if (key == KEY_W)
		ft_moving_forward(all);
	if (key == KEY_S)
		ft_moving_backward(all);
}
