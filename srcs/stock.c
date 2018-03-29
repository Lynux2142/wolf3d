/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:34:45 by lguiller          #+#    #+#             */
/*   Updated: 2018/03/29 13:36:07 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_read_file(char *name, char ***map)
{
	static char	start;
	t_parse		parse;
	
	if ((parse.fd = open(name, O_RDONLY)) == -1)
		ft_error("error", 1, perror);
	parse.i = 0;
	parse.line = 0;
	while (get_next_line(parse.fd, &parse.buff))
	{
		if (++parse.line > BUFF_SIZE)
			ft_error("error: Wrong column length", 1, ft_putendl_error);
		ft_check_map(parse.buff, &start);
		ft_memcpy(map[0][parse.i++], parse.buff, BUFF_SIZE);
		ft_memdel((void **)&parse.buff);
	}
	if (parse.line < BUFF_SIZE)
		ft_error("error: Wrong column lenght", 1, ft_putendl_error);
	if (start == 0)
		ft_error("error: No start found", 1, ft_putendl_error);
	ft_memdel((void **)&parse.buff);
	close(parse.fd);
}
