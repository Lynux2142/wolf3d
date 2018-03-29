/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:34:45 by lguiller          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/03/29 11:16:37 by lguiller         ###   ########.fr       */
=======
/*   Updated: 2018/03/29 14:55:38 by lguiller         ###   ########.fr       */
>>>>>>> test
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_read_file(char *name, char ***map)
{
<<<<<<< HEAD
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
=======
	t_parse		parse;
	static char	start;

	if ((parse.fd = open(name, O_RDONLY)) == -1)
		ft_error("error", 1, perror);
	parse.i = 0;
	while (get_next_line(parse.fd, &parse.buff) > 0)
	{
		if (++parse.i > BUFF_SIZE)
			ft_error("error: Wrong column length", 2, ft_putendl_error);
		ft_check_map(parse.buff, &start);
		ft_strcpy(map[0][parse.i - 1], parse.buff);
		ft_memdel((void **)&parse.buff);
	}
	ft_memdel((void **)&parse.buff);
	if (parse.i < BUFF_SIZE)
		ft_error("error: Wrong column lenght", 1, ft_putendl_error);
	if (start == 0)
		ft_error("error: No start found", 1, ft_putendl_error);
	if ((close(parse.fd)) == -1)
		ft_error("error", 1, perror);
>>>>>>> test
}
