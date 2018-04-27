/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:59:44 by bede-fre          #+#    #+#             */
/*   Updated: 2018/04/27 15:08:45 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static double	ft_screen_range(void)
{
	return ((double)FPX / 2.0 / tan(TO_RAD(FOV / 2.0)));
}

static int		ft_wall_height_on_screen(double dist)
{
	return ((int)(ft_screen_range() * (BLOCK_SIZE / 2.0) / dist));
}

void			ft_print_on_screen(t_raycast *rc, t_img *fp, int x)
{
	int	i;
	int	h;

	i = 0;
	h = ft_wall_height_on_screen(rc->dist);
	ft_fill_pixel(fp, x, (WINY / 2) + i, YELLOW);
	while ((++i + WINY / 2.0) <= WINY)
	{
		if (i > h)
		{
			ft_fill_pixel(fp, x, (WINY / 2) + i, BOTTOM);
			ft_fill_pixel(fp, x, (WINY / 2) - i, TOP);
		}
		else
		{
			ft_fill_pixel(fp, x, (WINY / 2) + i, YELLOW);
			ft_fill_pixel(fp, x, (WINY / 2) - i, YELLOW);
		}
	}
}
