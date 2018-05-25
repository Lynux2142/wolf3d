/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:24:19 by bede-fre          #+#    #+#             */
/*   Updated: 2018/05/25 14:15:27 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_key_press(int key, t_all *all)
{
	if (key == KEY_H)
		all->keys_tab[KEY_H] = (all->keys_tab[KEY_H] == FALSE) ? TRUE : FALSE;
	else
		all->keys_tab[key] = 1;
	if (key == ESC)
		exit(0);
	return (1);
}

int		ft_key_release(int key, t_all *all)
{
	if (key != KEY_H)
		all->keys_tab[key] = 0;
	return (1);
}
