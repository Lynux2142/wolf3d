/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 11:55:11 by lguiller          #+#    #+#             */
/*   Updated: 2018/04/27 15:31:43 by lguiller         ###   ########.fr       */
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

void		ft_print_all(t_img *info, t_raycast *rc, t_player *p, t_img *fp)
{
	int			i;
	double		a;

	ft_print_map(info, rc->map);
	a = p->a + TO_RAD(30.0);
	i = -1;
	while (++i < FPX)
	{
		ft_wall_dist(info, rc, p, a);
		ft_print_on_screen(rc, fp, i);
		a -= TO_RAD(RAY_ANGLE);
	}
}

void		ft_draw(t_raycast *rc, t_player *p)
{
	t_mlx	ptr;
	t_img	*info;
	t_img	*fp;
	t_all	all;

	info = &ptr.info;
	fp = &ptr.fp;
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, WINX, WINY, "wolf3d");
	info->img = mlx_new_image(ptr.mlx, INFOX, INFOY);
	fp->img = mlx_new_image(ptr.mlx, FPX, FPY);
	info->data = mlx_get_data_addr(info->img, &info->bpp, &info->sl,
		&info->endian);
	fp->data = mlx_get_data_addr(fp->img, &fp->bpp, &fp->sl, &fp->endian);
	all.rc = rc;
	all.p = p;
	all.fp = fp;
	all.ptr = ptr;
	all.info = info;
	mlx_hook(ptr.win, 2, (1L << 0), ft_key_funct, &all);
	ft_print_all(info, rc, p, fp);
	mlx_put_image_to_window(ptr.mlx, ptr.win, info->img, 0, 0);
	mlx_put_image_to_window(ptr.mlx, ptr.win, fp->img, INFOX + 1, 0);
	mlx_loop(ptr.mlx);
}
