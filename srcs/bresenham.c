/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 13:28:36 by bede-fre          #+#    #+#             */
/*   Updated: 2018/05/28 11:15:13 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_fill_line(t_algo_brez algo, t_img *ptr, int col, t_player *p)
{
	algo.cumul = algo.da / 2;
	while (algo.i <= algo.da)
	{
		algo.a += algo.cpta;
		algo.cumul += algo.db;
		if (algo.cumul >= algo.da)
		{
			algo.cumul -= algo.da;
			algo.b += algo.cptb;
		}
		if (20.0 < sqrtf(powf((double)algo.a - (p->x / 8.0), 2.0) +
		powf((p->y / 8.0) - (double)algo.b, 2.0)))
			break ;
		ft_fill_pixel(ptr, algo.a, algo.b, col);
		algo.i++;
	}
}

static void	ft_fill_column(t_algo_brez algo, t_img *ptr, int col, t_player *p)
{
	algo.cumul = algo.db / 2;
	while (algo.i <= algo.db)
	{
		algo.b += algo.cptb;
		algo.cumul += algo.da;
		if (algo.cumul >= algo.db)
		{
			algo.cumul -= algo.db;
			algo.a += algo.cpta;
		}
		if (20.0 < sqrtf(powf((double)algo.a - (p->x / 8.0), 2.0) +
		powf((p->y / 8.0) - (double)algo.b, 2.0)))
			break ;
		ft_fill_pixel(ptr, algo.a, algo.b, col);
		algo.i++;
	}
}

void		ft_algo(t_img *ptr, t_ray ray, t_player *p, int col)
{
	t_algo_brez	algo;

	algo.a = (int)(p->x / 8.0);
	algo.b = (int)(p->y / 8.0);
	algo.da = (int)((ray.x - p->x) / 8.0);
	algo.db = (int)((ray.y - p->y) / 8.0);
	algo.cpta = (algo.da > 0) ? 1 : -1;
	algo.cptb = (algo.db > 0) ? 1 : -1;
	algo.da = ft_abs(algo.da);
	algo.db = ft_abs(algo.db);
	algo.i = 1;
	ft_fill_pixel(ptr, algo.a, algo.b, col);
	if (algo.da > algo.db)
		ft_fill_line(algo, ptr, col, p);
	else
		ft_fill_column(algo, ptr, col, p);
}
