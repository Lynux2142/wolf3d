/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:16:31 by lguiller          #+#    #+#             */
/*   Updated: 2018/05/14 10:31:25 by lguiller         ###   ########.fr       */
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
	ft_draw(all, av[1]);
	ft_free_map(all.rc.map);
	return (0);
}
