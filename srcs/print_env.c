/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:59:44 by bede-fre          #+#    #+#             */
/*   Updated: 2018/06/01 12:33:41 by bede-fre         ###   ########.fr       */
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

static int		ft_color_textures(double cpt, int column, t_img *ptr)
{
	return (ft_rgba(ptr->data[column * 4 + ((int)(CAM_HEIGHT + cpt) * ptr->sl) + 2],
		ptr->data[column * 4 + ((int)(CAM_HEIGHT + cpt) * ptr->sl) + 1],
		ptr->data[column * 4 + ((int)(CAM_HEIGHT + cpt) * ptr->sl)],
		ptr->data[column * 4 + ((int)(CAM_HEIGHT + cpt) * ptr->sl) + 3]));
}

static void		ft_print_textures(t_all *all, int x, int i, double h)
{
	int		column;
	int		color1;
	int		color2;
	double	cpt;

	if (all->rc.ray.hit == N_W || all->rc.ray.hit == S_W)
		column = (int)(all->rc.ray.x - (double)ft_roundminf(all->rc.ray.x, BLOCK_SIZE));
	else
		column = (int)(all->rc.ray.y - (double)ft_roundminf(all->rc.ray.y, BLOCK_SIZE));
	cpt = (double)i * (BLOCK_SIZE / (h * 2.0));
	if (all->rc.ray.hit == N_W)
	{
		color1 = ft_color_textures(cpt, column, &all->textures.img_n);
		color2 = ft_color_textures(-cpt, column, &all->textures.img_n);
	}
	if (all->rc.ray.hit == S_W)
	{
		color1 = ft_color_textures(cpt, column, &all->textures.img_s);
		color2 = ft_color_textures(-cpt, column, &all->textures.img_s);
	}
	if (all->rc.ray.hit == E_W)
	{
		color1 = ft_color_textures(cpt, column, &all->textures.img_e);
		color2 = ft_color_textures(-cpt, column, &all->textures.img_e);
	}
	if (all->rc.ray.hit == W_W)
	{
		color1 = ft_color_textures(cpt, column, &all->textures.img_w);
		color2 = ft_color_textures(-cpt, column, &all->textures.img_w);
	}
	ft_fill_pixel(&all->fp, x, (WINY / 2) + i, color1);
	ft_fill_pixel(&all->fp, x, (WINY / 2) - i, color2);
}

void			ft_print_on_screen(t_all *all, int x, double lens)
{
	int		i;
	double	h;

	i = -1;
	h = ft_wall_height_on_screen(all->rc.ray.dist * cos(lens));
	while ((++i + (WINY / 2)) <= WINY)
	{
		if ((double)i >= h)
		{
			ft_fill_pixel(&all->fp, x, (WINY / 2) - i, TOP);
			ft_fill_pixel(&all->fp, x, (WINY / 2) + i, BOTTOM);
		}
		else
		{
			if (all->txtrs == TRUE)
				ft_print_textures(all, x, i, h);
			else if (all->txtrs == FALSE)
			{
				ft_fill_pixel(&all->fp, x, (WINY / 2) + i, all->rc.ray.hit);
				ft_fill_pixel(&all->fp, x, (WINY / 2) - i, all->rc.ray.hit);
			}
		}
	}
}
