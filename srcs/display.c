/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 11:55:11 by lguiller          #+#    #+#             */
/*   Updated: 2018/05/25 17:28:55 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_init(t_all *all, char *title)
{
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

static void	*ft_test_thread(void *ptr)
{
	t_all *all;

	all = (t_all *)ptr;
	ft_wall_dist(&all->info, &all->rc, &all->p, all->a);
//	pthread_exit(NULL);
	return (NULL);
}

void		ft_print_all(t_all *all)
{
//	pthread_t	p[FPX];
	int			i;
	double		lens;

	all->a = all->p.a + TO_RAD(30.0);
	lens = TO_RAD(FOV / 2.0) * all->keys_tab[KEY_H];
	i = -1;
	ft_background_color(&all->info);
	while (++i < FPX)
	{
//		pthread_create(&p[i], NULL, ft_test_thread, all);
		ft_test_thread(all);
		ft_print_on_screen(&all->rc, &all->fp, i, lens);
		lens -= TO_RAD(RAY_ANGLE) * all->keys_tab[KEY_H];
		all->a -= TO_RAD(RAY_ANGLE);
	}
//	i = -1;
//	while (++i < FPX)
//		pthread_join(p[i], NULL);
	ft_print_map(&all->info, all->rc.map);
}

void		ft_draw(t_all all, char *name)
{
	char	*title;

	title = ft_strjoin("wolf3d - ", name + 5);
	ft_init(&all, title);
	mlx_hook(all.ptr.win, 2, (1L << 0), ft_key_press, &all);
	mlx_hook(all.ptr.win, 3, (1L << 1), ft_key_release, &all);
	mlx_hook(all.ptr.win, 4, (1L << 2), ft_mouse, &all);
	mlx_loop_hook(all.ptr.mlx, ft_movements, &all);
	ft_print_all(&all);
	mlx_loop(all.ptr.mlx);
}
