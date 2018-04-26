/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:59:44 by bede-fre          #+#    #+#             */
/*   Updated: 2018/04/26 15:50:38 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static double	ft_screen_range(void)
{
	return ((double)SCRNX / 2.0 / tan(TO_RAD(FOV / 2.0)));
}

static int	ft_wall_height_on_screen(double dist)
{
	return ((int)(ft_screen_range() * (BLOCK_SIZE / 2.0) / dist));
}

void		ft_print_on_screen(t_raycast rc, t_img *fp, int x)
{
	int	i;
	int	h;

	i = -1;
	h = ft_wall_height_on_screen(rc.dist);
	while (++i <= h)
	{
		ft_fill_pixel(fp, x, (WINY / 2) + i, WALL_COLOR);
		ft_fill_pixel(fp, x, (WINY / 2) - i, WALL_COLOR);
	}
}
