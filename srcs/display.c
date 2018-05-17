/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 11:55:11 by lguiller          #+#    #+#             */
/*   Updated: 2018/05/17 09:56:03 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_init(t_all *all, char *title)
{
	all->rc.f_eye = FALSE;
	all->ptr.mlx = mlx_init();
	all->ptr.win = mlx_new_window(all->ptr.mlx, WINX, WINY, title);
	all->info.img = mlx_new_image(all->ptr.mlx, INFOX, INFOY);
	all->fp.img = mlx_new_image(all->ptr.mlx, FPX, FPY);
	all->info.data = mlx_get_data_addr(all->info.img, &all->info.bpp,
		&all->info.sl, &all->info.endian);
	all->fp.data = mlx_get_data_addr(all->fp.img, &all->fp.bpp, &all->fp.sl,
		&all->fp.endian);
}

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
	double		lens;

	a = p->a + TO_RAD(30.0);
	i = -1;
	lens = TO_RAD(FOV / 2.0) * rc->f_eye;
	while (++i < FPX)
	{
		ft_wall_dist(info, rc, p, a);
		ft_print_on_screen(rc, fp, i, lens);
		lens -= TO_RAD(RAY_ANGLE) * rc->f_eye;
		a -= TO_RAD(RAY_ANGLE);
	}
	ft_print_map(info, rc->map);
}

void		ft_draw(t_all all, char *name)
{
	char	*title;

	title = ft_strjoin("wolf3d - ", name + 5);
	ft_init(&all, title);
	mlx_hook(all.ptr.win, 2, (1L << 0), ft_key_funct, &all);
	mlx_hook(all.ptr.win, 4, (1L << 2), ft_mouse, &all);
	ft_print_all(&all.info, &all.rc, &all.p, &all.fp);
	mlx_put_image_to_window(all.ptr.mlx, all.ptr.win, all.info.img, 0, 0);
	mlx_put_image_to_window(all.ptr.mlx, all.ptr.win, all.fp.img, INFOX + 1, 0);
	mlx_loop(all.ptr.mlx);
}
