/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:59:44 by bede-fre          #+#    #+#             */
/*   Updated: 2018/05/29 09:23:08 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static double	ft_screen_range(void)
{
	return ((double)FPX / 2.0 / tan(TO_RAD(FOV / 2.0)));
}

static int		ft_wall_height_on_screen(double dist)
{
	return ((int)(ft_screen_range() * (CAM_HEIGHT) / dist));
}

void			ft_print_on_screen(t_raycast *rc, t_img *fp, int x, double a)
{
	int		i;
	double	h;

	i = -1;
	h = ft_wall_height_on_screen(rc->ray.dist * cos(a));
	while ((++i + (WINY / 2)) <= WINY)
	{
		if ((double)i > h)
		{
			ft_fill_pixel(fp, x, (WINY / 2) - i, TOP);
			ft_fill_pixel(fp, x, (WINY / 2) + i, BOTTOM);
		}
		else
		{
			ft_fill_pixel(fp, x, (WINY / 2) + i, rc->ray.hit);
			ft_fill_pixel(fp, x, (WINY / 2) - i, rc->ray.hit);
		}
	}
}
