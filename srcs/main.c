/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:16:31 by lguiller          #+#    #+#             */
/*   Updated: 2018/04/26 10:43:47 by bede-fre         ###   ########.fr       */
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
	t_player		p;
	t_raycast		rc;

	if (ac != 2)
		ft_error("usage: ./wolf3d [map_name]", 1, ft_putendl);
	ft_malloc_map(&rc.map);
	ft_read_file(av[1], &rc.map);
	ft_init_player(rc.map, &p);
	ft_wall_dist(&rc, &p);
	ft_draw(rc, rc.ray, p);
	ft_free_map(rc.map);
	return (0);
}
