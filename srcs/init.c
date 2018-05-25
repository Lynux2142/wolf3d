/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 18:22:58 by lguiller          #+#    #+#             */
/*   Updated: 2018/05/25 15:28:57 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_init_player(char map[MAPY][MAPX], t_player *p)
{
	int	x;
	int	y;

	y = -1;
	while (++y < MAPY)
	{
		x = -1;
		while (++x < MAPX)
		{
			if (map[y][x] == 's')
			{
				p->x = (double)x * BLOCK_SIZE + (BLOCK_SIZE / 2.0);
				p->y = (double)y * BLOCK_SIZE + (BLOCK_SIZE / 2.0);
				p->a = TO_RAD(180.0);
				break ;
			}
		}
	}
}

void	ft_init_keys_tab(int (*keys_tab)[280])
{
	int i;

	i = -1;
	while (++i < 280)
		keys_tab[0][i] = 0;
}
