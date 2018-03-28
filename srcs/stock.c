/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:34:45 by lguiller          #+#    #+#             */
/*   Updated: 2018/03/28 18:19:05 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_read_file(char *name)
{
	char	fd;
	char	**map;
	int		i;

	errno = 0;
	if ((fd = open(name, O_RDONLY)) == -1)
		ft_error("error", 1);
	if (!(map = (char **)ft_memalloc(sizeof(char *) * BUFF_SIZE)))
		return ;
	i = -1;
	while (++i < BUFF_SIZE)
		if (!(map[i] = (char *)ft_strnew(sizeof(char) * BUFF_SIZE)))
			return ;
	i = 0;
	while (get_next_line(fd, (char **)&map[i]))
		++i;
	i = -1;
	while (map[++i])
		ft_putendl(map[i]);
	i = -1;
	while (map[++i])
		ft_memdel((void **)&map[i]);
	ft_memdel((void **)&map);
	close(fd);
	while (1);
}
