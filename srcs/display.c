/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 11:55:11 by lguiller          #+#    #+#             */
/*   Updated: 2018/04/26 18:00:57 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_fill_pixel(t_img *ptr, int x, int y, int col)
{
	if ((y >= 0 && y < WINY) && (x >= 0 && x < WINX))
	{
		if (ptr->endian == 0 && ptr->bpp == (8 * 4))
		{
			((char *)(ptr->data))[((x * 4) + (y * ptr->sl))] =
				(char)col;
			((char *)(ptr->data))[((x * 4) + (y * ptr->sl)) + 1] =
				(char)(col >> 8);
			((char *)(ptr->data))[((x * 4) + (y * ptr->sl)) + 2] =
				(char)(col >> 16);
			((char *)(ptr->data))[((x * 4) + (y * ptr->sl)) + 3] =
				0;
		}
	}
}

static void	ft_full_print(t_raycast *rc, t_player *p, t_img *fp)
{
	int			i;

	p->a += TO_RAD(30.0);
	i = -1;
	while (++i < FPX)
	{
		ft_wall_dist(rc, p);
		ft_print_on_screen(rc, fp, i);
		p->a -= TO_RAD(RAY_ANGLE);
	}
}

void		ft_draw(t_raycast *rc, t_player *p)
{
	t_mlx	ptr;
	t_img	*info;
	t_img	*fp;

	info = &ptr.info;
	fp = &ptr.fp;
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, WINX, WINY, "wolf3d");
	info->img = mlx_new_image(ptr.mlx, INFOX, INFOY);
	fp->img = mlx_new_image(ptr.mlx, FPX, FPY);
	info->data = mlx_get_data_addr(info->img, &info->bpp, &info->sl,
		&info->endian);
	fp->data = mlx_get_data_addr(fp->img, &fp->bpp, &fp->sl, &fp->endian);
	ft_full_print(rc, p, fp);
	ft_print_map(info, rc->map);
	ft_algo(info, rc->ray, p, 0xFF0000);
	mlx_put_image_to_window(ptr.mlx, ptr.win, info->img, 0, 0);
	mlx_put_image_to_window(ptr.mlx, ptr.win, fp->img, INFOX + 1, 0);
	mlx_hook(ptr.win, 2, (1L << 0), ft_key_funct, 0);
	mlx_loop(ptr.mlx);
}
