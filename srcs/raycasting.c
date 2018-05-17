/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 14:06:10 by lguiller          #+#    #+#             */
/*   Updated: 2018/05/17 14:57:45 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_dist(char map[MAPY][MAPX], t_ray *ray, t_player *p)
{
	int		i;

	ray->x = ray->fx;
	ray->y = ray->fy;
	i = 0;
	while (ray->x >= 0.0 && ray->x < (MAPX * BLOCK_SIZE)
		&& ray->y >= 0.0 && ray->y < (MAPY * BLOCK_SIZE)
		&& map[TO_MAP(ray->y)][TO_MAP(ray->x)] != WALL
		&& map[TO_MAP(ray->y)][TO_MAP(ray->x)] != SECRET)
	{
		ray->x += ray->xa;
		ray->y += ray->ya;
		++i;
	}
	ray->dx = fabs(p->x - ray->x);
	ray->dy = fabs(p->y - ray->y);
	ray->dist = sqrt(pow(ray->dx, 2) + pow(ray->dy, 2));
}

static void	ft_fp_hori(t_ray *ray, t_player *p, char map[MAPY][MAPX], double a)
{
	if (a == WEST || a == EAST || a == EAST2)
		ray->fy = p->y;
	else if (sin(a) >= 0)
		ray->fy = (double)(ft_roundminf((int)p->y, (int)BLOCK_SIZE)) - LITTLE;
	else
		ray->fy = (double)(ft_roundmsup((int)p->y, (int)BLOCK_SIZE));
	ray->fx = p->x + (p->y - ray->fy) / tan(a);
	ray->ya = (sin(a) >= 0) ? -BLOCK_SIZE : BLOCK_SIZE;
	ray->xa = -ray->ya / tan(a);
	ft_dist(map, ray, p);
	ray->hit = (sin(a) > 0) ? N_W : S_W;
}

static void	ft_fp_vert(t_ray *ray, t_player *p, char map[MAPY][MAPX], double a)
{
	if (a == NORTH || a == SOUTH)
		ray->fx = p->x;
	else if (cos(a) < 0)
		ray->fx = (double)(ft_roundminf((int)p->x, (int)BLOCK_SIZE)) - LITTLE;
	else
		ray->fx = (double)(ft_roundmsup((int)p->x, (int)BLOCK_SIZE));
	ray->fy = p->y + (p->x - ray->fx) * tan(a);
	ray->xa = (cos(a) < 0) ? -BLOCK_SIZE : BLOCK_SIZE;
	ray->ya = -ray->xa * tan(a);
	ft_dist(map, ray, p);
	ray->hit = (cos(a) > 0) ? W_W : E_W;
}

void		ft_wall_dist(t_img *info, t_raycast *rc, t_player *p, double a)
{
	ft_fp_hori(&rc->ray_h, p, rc->map, a);
	ft_fp_vert(&rc->ray_v, p, rc->map, a);
	if (rc->ray_h.dist != rc->ray_h.dist || rc->ray_v.dist != rc->ray_v.dist)
		rc->ray = (rc->ray_h.dist != rc->ray_h.dist) ? rc->ray_v : rc->ray_h;
	else
		rc->ray = (rc->ray_h.dist <= rc->ray_v.dist) ? rc->ray_h : rc->ray_v;
	ft_algo(info, rc->ray, p, YELLOW);
}
