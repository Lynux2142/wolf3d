/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:16:31 by lguiller          #+#    #+#             */
/*   Updated: 2018/03/29 14:18:40 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_usage(void)
{
	ft_putendl("usage: ./wolf3d [map_name]");
	exit(1);
}

static void	ft_malloc_map(char ***map)
{
	int		i;

	if (!(map[0] = (char **)ft_memalloc(sizeof(char *) * BUFF_SIZE + 1)))
		ft_error("error", 1, perror);
	i = -1;
	while (++i < BUFF_SIZE)
		if (!(map[0][i] = (char *)ft_strnew(sizeof(char) * BUFF_SIZE)))
			ft_error("error", 1, perror);
}

int			main(int ac, char **av)
{
	char	**map;
	int		i;

	if (ac != 2)
		ft_usage();
	ft_malloc_map(&map);
	ft_read_file(av[1], &map);
	i = -1;
	while (++i < BUFF_SIZE)
		ft_putendl(map[i]);
	ft_free_map(map);
	return (0);
}
