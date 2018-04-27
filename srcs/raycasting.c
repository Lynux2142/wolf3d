/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 14:06:10 by lguiller          #+#    #+#             */
/*   Updated: 2018/04/27 11:25:23 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_dist(char **map, t_ray *ray, t_player *p)
{
	int		i;

	ray->x = ray->fx;
	ray->y = ray->fy;
	i = 0;
	while (TO_MAP(ray->x) >= 0 && TO_MAP(ray->x) < MAPX
			&& TO_MAP(ray->y) >= 0 && TO_MAP(ray->y) < MAPY
			&& map[TO_MAP(ray->y)][TO_MAP(ray->x)] != WALL)
	{
		ray->x += ray->xa;
		ray->y += ray->ya;
		++i;
	}
	ray->dx = ft_fabs(p->x - ray->x);
	ray->dy = ft_fabs(p->y - ray->y);
}

static void	ft_fp_hori(t_ray *ray, t_player *p, char **map, double a)
{
	if (a == WEST || a == EAST || a == EAST2)
		ray->fy = p->y;
	else if ((sin(a) * BLOCK_SIZE) >= 0)
		ray->fy = (double)(ft_roundminf((int)p->y, (int)BLOCK_SIZE) - 1);
	else
		ray->fy = (double)(ft_roundmsup((int)p->y, (int)BLOCK_SIZE) + 1);
	ray->fx = p->x + (p->y - ray->fy) / tan(a);
	ray->ya = ((sin(a) * BLOCK_SIZE) >= 0) ? -BLOCK_SIZE : BLOCK_SIZE;
	ray->xa = -ray->ya / tan(a);
	ft_dist(map, ray, p);
}

static void	ft_fp_vert(t_ray *ray, t_player *p, char **map, double a)
{
	if (a == NORTH || a == SOUTH)
		ray->fx = p->x;
	else if ((cos(a) * BLOCK_SIZE) < 0)
		ray->fx = (double)(ft_roundminf((int)p->x, (int)BLOCK_SIZE) - 1.0);
	else
		ray->fx = (double)(ft_roundmsup((int)p->x, (int)BLOCK_SIZE) + 1.0);
	ray->fy = p->y + (p->x - ray->fx) * tan(a);
	ray->xa = ((cos(a) * BLOCK_SIZE) < 0) ?
		-BLOCK_SIZE : BLOCK_SIZE;
	ray->ya = -ray->xa * tan(a);
	ft_dist(map, ray, p);
}

void		ft_wall_dist(t_raycast *rc, t_player *p, double a)
{
	double	dist_hori;
	double	dist_vert;

	ft_fp_hori(&rc->r_hori, p, rc->map, a);
	ft_fp_vert(&rc->r_vert, p, rc->map, a);
	dist_hori = sqrt(ft_fpow(rc->r_hori.dx, 2) + ft_fpow(rc->r_hori.dy, 2));
	dist_vert = sqrt(ft_fpow(rc->r_vert.dx, 2) + ft_fpow(rc->r_vert.dy, 2));
	if (dist_hori != dist_hori || dist_vert != dist_vert)
		rc->dist = (dist_hori != dist_hori) ? dist_vert : dist_hori;
	else
		rc->dist = (dist_hori <= dist_vert) ? dist_hori : dist_vert;
	rc->ray = (dist_hori <= dist_vert) ? rc->r_hori : rc->r_vert;
}
