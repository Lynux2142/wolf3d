/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:16:31 by lguiller          #+#    #+#             */
/*   Updated: 2018/05/07 15:06:14 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_malloc_map(char ***map)
{
	int	i;

	if (!(map[0] = (char **)ft_memalloc(sizeof(char *) * BUFF_SIZE + 1)))
		ft_error("error", 1, perror);
	i = -1;
	while (++i < BUFF_SIZE)
		if (!(map[0][i] = (char *)ft_strnew(sizeof(char) * BUFF_SIZE)))
			ft_error("error", 1, perror);
}

int			main(int ac, char **av)
{
	t_all		all;

	if (ac != 2)
		ft_error("usage: ./wolf3d [map_name]", 1, ft_putendl);
	ft_malloc_map(&all.rc.map);
	ft_read_file(av[1], &all.rc.map);
	ft_init_player(all.rc.map, &all.p);
	ft_draw(all, av[1]);
	ft_free_map(all.rc.map);
	return (0);
}
