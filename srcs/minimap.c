/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 11:55:11 by lguiller          #+#    #+#             */
/*   Updated: 2018/05/14 14:14:17 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_rect(t_img *ptr, int x, int y, int c)
{
	t_coord	p1;
	t_coord	p2;
	int		zoom;

	zoom = 8;
	p1.y = (y *= zoom);
	p2.x = (x *= zoom) + zoom;
	p2.y = y + zoom;
	while (p1.y <= p2.y)
	{
		p1.x = x;
		while (p1.x <= p2.x)
		{
			ft_fill_pixel(ptr, p1.x, p1.y,
			(p1.x == x || p1.x == p2.x || p1.y == y || p1.y == p2.y) ? 0 : c);
			++p1.x;
		}
		++p1.y;
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
			if (map[y][x] == START || map[y][x] == WALL || map[y][x] == SECRET)
			{
				if (map[y][x] == WALL)
					ft_rect(ptr, x, y, WHITE);
				else
					ft_rect(ptr, x, y, (map[y][x] == SECRET) ? GREY : GREEN);
			}
		}
	}
}
