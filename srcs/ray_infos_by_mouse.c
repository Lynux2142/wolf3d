/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_infos_by_mouse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 09:23:30 by bede-fre          #+#    #+#             */
/*   Updated: 2018/05/21 09:55:47 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			ft_mouse(int key, int x, int y, t_all *all)
{
	double a;

	(void)y;
	a = all->p.a - TO_RAD(((x - INFOX - 1) - (FPX / 2) - 1) * RAY_ANGLE);
	if (key == 1)
	{
		all->p.ray_infos = 1;
		ft_wall_dist(&all->info, &all->rc, &all->p, a);
		all->p.ray_infos = 0;
	}
	return (0);
}
