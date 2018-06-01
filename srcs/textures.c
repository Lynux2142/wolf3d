/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:34:17 by bede-fre          #+#    #+#             */
/*   Updated: 2018/06/01 12:18:06 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_init_textures(t_all *all, t_textures *textures)
{
	textures->img_n.img = mlx_xpm_file_to_image(all->ptr.mlx,
		"./textures/wood.xpm", &textures->width, &textures->height);
	textures->img_s.img = mlx_xpm_file_to_image(all->ptr.mlx,
		"./textures/bluestone.xpm", &textures->width, &textures->height);
	textures->img_e.img = mlx_xpm_file_to_image(all->ptr.mlx,
		"./textures/mossy.xpm", &textures->width, &textures->height);
	textures->img_w.img = mlx_xpm_file_to_image(all->ptr.mlx,
		"./textures/greystone.xpm", &textures->width, &textures->height);
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
