/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:24:19 by bede-fre          #+#    #+#             */
/*   Updated: 2018/05/22 14:01:55 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_key_press(int key, t_all *all)
{
	all->keys_tab[KEY_A] = (key == KEY_A) ? TRUE : all->keys_tab[KEY_A];
	all->keys_tab[KEY_W] = (key == KEY_W) ? TRUE : all->keys_tab[KEY_W];
	all->keys_tab[KEY_S] = (key == KEY_S) ? TRUE : all->keys_tab[KEY_S];
	all->keys_tab[KEY_D] = (key == KEY_D) ? TRUE : all->keys_tab[KEY_D];
	all->keys_tab[KEY_Q] = (key == KEY_Q) ? TRUE : all->keys_tab[KEY_Q];
	all->keys_tab[KEY_E] = (key == KEY_E) ? TRUE : all->keys_tab[KEY_E];
	all->keys_tab[KEY_H] = (key == KEY_H && all->keys_tab[KEY_H] == 0) ? 1 : 0;
	if (key == ESC)
		exit(0);
	return (1);
}

int		ft_key_release(int key, t_all *all)
{
	all->keys_tab[KEY_A] = (key == KEY_A) ? FALSE : all->keys_tab[KEY_A];
	all->keys_tab[KEY_W] = (key == KEY_W) ? FALSE : all->keys_tab[KEY_W];
	all->keys_tab[KEY_S] = (key == KEY_S) ? FALSE : all->keys_tab[KEY_S];
	all->keys_tab[KEY_D] = (key == KEY_D) ? FALSE : all->keys_tab[KEY_D];
	all->keys_tab[KEY_Q] = (key == KEY_Q) ? FALSE : all->keys_tab[KEY_Q];
	all->keys_tab[KEY_E] = (key == KEY_E) ? FALSE : all->keys_tab[KEY_E];
	return (1);
}
