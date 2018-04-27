/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:24:19 by bede-fre          #+#    #+#             */
/*   Updated: 2018/04/27 11:34:46 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_key_funct(int key, t_all *all)
{
	if (key == KEY_A)
		all->p->a += TO_RAD(4.0);
	if (key == KEY_D)
		all->p->a -= TO_RAD(4.0);
	if (key == ESC)
		exit(0);
	ft_print_all(all->rc, all->p, all->fp);
	mlx_put_image_to_window(all->ptr.mlx, all->ptr.win, all->info->img, 0, 0);
	mlx_put_image_to_window(all->ptr.mlx, all->ptr.win, all->fp->img,
		INFOX + 1, 0);
	return (1);
}
