/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 11:55:11 by lguiller          #+#    #+#             */
/*   Updated: 2018/05/29 12:57:17 by lguiller         ###   ########.fr       */
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
	while (++p1.y < p2.y)
	{
		p1.x = x;
		while (++p1.x < p2.x)
			ft_fill_pixel(ptr, p1.x - 1, p1.y - 1, c);
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

	ft_background_color(ptr);
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
