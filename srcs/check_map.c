/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 12:40:30 by bede-fre          #+#    #+#             */
/*   Updated: 2018/04/03 10:52:03 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_check_line_length(char *buff)
{
	if (ft_strlen(buff) != BUFF_SIZE)
		ft_error("error: Wrong line length", 1, ft_puterror);
}

static void	ft_check_start(char *buff, short i, char *start)
{
	while (++i < BUFF_SIZE)
	{
		if (buff[i] == 's')
			++start[0];
		if (start[0] > 1)
			ft_error("error: More than one start", 1, ft_puterror);
	}
}

static void	ft_check_char(char *buff, short i)
{
	while (++i < BUFF_SIZE)
		if (buff[i] != ' ' && buff[i] != '1' && buff[i] != 's')
			ft_error("error: Wrong character found", 1, ft_puterror);
}

void		ft_check_map(char *buff, char *start)
{
	ft_check_line_length(buff);
	ft_check_start(buff, -1, start);
	ft_check_char(buff, -1);
}
