/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 18:22:58 by lguiller          #+#    #+#             */
/*   Updated: 2018/06/01 14:36:23 by lguiller         ###   ########.fr       */
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

void	ft_init_textures(t_all *all, t_textures *textures)
{
	textures->img_n.img = mlx_xpm_file_to_image(all->ptr.mlx,
		TEXT_NORTH, &textures->width, &textures->height);
	textures->img_s.img = mlx_xpm_file_to_image(all->ptr.mlx,
		TEXT_SOUTH, &textures->width, &textures->height);
	textures->img_e.img = mlx_xpm_file_to_image(all->ptr.mlx,
		TEXT_EAST, &textures->width, &textures->height);
	textures->img_w.img = mlx_xpm_file_to_image(all->ptr.mlx,
		TEXT_WEST, &textures->width, &textures->height);
	if (textures->img_n.img == NULL || textures->img_s.img == NULL
		|| textures->img_e.img == NULL || textures->img_w.img == NULL)
		ft_error("error", 8, perror);
	textures->img_n.data = mlx_get_data_addr(textures->img_n.img,
		&textures->img_n.bpp, &textures->img_n.sl, &textures->img_n.endian);
	textures->img_s.data = mlx_get_data_addr(textures->img_s.img,
		&textures->img_s.bpp, &textures->img_s.sl, &textures->img_s.endian);
	textures->img_e.data = mlx_get_data_addr(textures->img_e.img,
		&textures->img_e.bpp, &textures->img_e.sl, &textures->img_e.endian);
	textures->img_w.data = mlx_get_data_addr(textures->img_w.img,
		&textures->img_w.bpp, &textures->img_w.sl, &textures->img_w.endian);
	all->txtrs = TRUE;
}
