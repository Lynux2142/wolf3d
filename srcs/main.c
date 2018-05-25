/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:16:31 by lguiller          #+#    #+#             */
/*   Updated: 2018/05/25 15:27:44 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			main(int ac, char **av)
{
	t_all		all;

	if (ac != 2)
		ft_error("usage: ./wolf3d [map_name]", 1, ft_putendl);
	ft_read_file(av[1], &all.rc.map);
	ft_init_player(all.rc.map, &all.p);
	ft_init_keys_tab(&all.keys_tab);
	ft_draw(all, av[1]);
	ft_free_map(all.rc.map);
	return (0);
}
