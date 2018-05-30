/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 11:55:11 by lguiller          #+#    #+#             */
/*   Updated: 2018/05/30 13:18:53 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_rect(t_img *ptr, int x, int y, int c)
{
	t_coord	p1;
	t_coord	p2;

	p1.y = (y *= (int)ZOOM);
	p2.x = (x *= (int)ZOOM) + (int)ZOOM;
	p2.y = y + (int)ZOOM;
	while (p1.y <= p2.y)
	{
		p1.x = x;
		while (p1.x <= p2.x)
		{
			ft_fill_pixel(ptr, p1.x, p1.y,
			(p1.x == x || p1.y == y || p1.x == p2.x || p1.y == p2.y) ? B_G : c);
			++p1.x;
		}
		++p1.y;
	}
}

void		ft_perso(t_img *ptr, double x, double y)
{
	t_fcoord	p1;
	t_fcoord	p2;

	p1.y = -P_SIZE;
	p2.x = P_SIZE;
	p2.y = P_SIZE;
	while (++p1.y <= p2.y)
	{
		p1.x = -P_SIZE;
		while (++p1.x <= p2.x)
			ft_fill_pixel(ptr, x / ZOOM + p1.x, y / ZOOM + p1.y, RED);
	}
}

void		ft_background_color(t_img *ptr)
{
	int	x;
	int	y;

	y = -1;
	while (++y <= INFOY)
	{
		x = -1;
		while (++x <= INFOX)
			ft_fill_pixel(ptr, x, y, B_G);
	}
}

void		ft_print_map(t_img *ptr, char map[MAPY][MAPX])
{
	int		x;
	int		y;

	y = -1;
	while (++y < BUFF_SIZE)
	{
		x = -1;
		while (++x < BUFF_SIZE)
		{
			if (map[y][x] == WALL)
				ft_rect(ptr, x, y, WHITE);
			else if (map[y][x] == SECRET)
				ft_rect(ptr, x, y, GREY);
			else if (map[y][x] == TP_S)
				ft_rect(ptr, x, y, LIGHT_GREEN);
			else if (map[y][x] == TP_E)
				ft_rect(ptr, x, y, GREEN);
		}
	}
}
