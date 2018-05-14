/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:34:45 by lguiller          #+#    #+#             */
/*   Updated: 2018/05/14 10:14:45 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_read_file(char *name, char (*map)[MAPY][MAPX])
{
	t_parse		parse;
	static char	start;
	int			test_gnl;

	if ((parse.fd = open(name, O_RDONLY)) == -1)
		ft_error("error", 1, perror);
	parse.i = 0;
	while ((test_gnl = get_next_line(parse.fd, &parse.buff)) > 0)
	{
		if (++parse.i > BUFF_SIZE)
			ft_error("error: Wrong column length", 2, ft_puterror);
		ft_check_map(parse.buff, &start);
		ft_strcpy(map[0][parse.i - 1], parse.buff);
		ft_memdel((void **)&parse.buff);
	}
	ft_memdel((void **)&parse.buff);
	if (test_gnl == -1)
		ft_error("error: Not valid file", 1, ft_puterror);
	if (parse.i < BUFF_SIZE)
		ft_error("error: Wrong column lenght", 4, ft_puterror);
	if (start == 0)
		ft_error("error: No start found", 1, ft_puterror);
	if ((close(parse.fd)) == -1)
		ft_error("error", 1, perror);
}
