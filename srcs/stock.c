/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:34:45 by lguiller          #+#    #+#             */
/*   Updated: 2018/03/29 11:16:37 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_read_file(char *name, char ***map)
{
	char	fd;
	char	*line;
	int		i;

	if ((fd = open(name, O_RDONLY)) == -1)
		ft_error("error", 1, perror);
	i = 0;
	while (get_next_line(fd, &line))
	{
		ft_memcpy(map[0][i++], line, BUFF_SIZE);
		ft_memdel((void **)&line);
	}
	ft_memdel((void **)&line);
	close(fd);
}
