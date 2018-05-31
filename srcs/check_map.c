/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 12:40:30 by bede-fre          #+#    #+#             */
/*   Updated: 2018/05/31 13:46:17 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_check_line_length(char *buff)
{
	if (ft_strlen(buff) != BUFF_SIZE)
		ft_error("error: Wrong line length", 12, ft_puterror);
}

static void	ft_check_start(char *buff, short i, char (*start)[2])
{
	while (++i < BUFF_SIZE)
	{
		if (buff[i] == 's')
			++(*start[0]);
		if (buff[i] == '4')
			++(*start[1]);
		if (*start[0] > 1)
			ft_error("error: More than one start", 1, ft_puterror);
		if (*start[1] > 1)
			ft_error("error: More than one TP", 1, ft_puterror);
	}
}

static void	ft_check_char(char *buff, short i)
{
	while (++i < BUFF_SIZE)
		if (buff[i] != FLOOR && buff[i] != WALL && buff[i] != START
			&& buff[i] != SECRET && buff[i] != TP_S && buff[i] != TP_E)
			ft_error("error: Wrong character found", 1, ft_puterror);
}

void		ft_check_map(char *buff, char (*start)[2])
{
	ft_check_line_length(buff);
	ft_check_start(buff, -1, start);
	ft_check_char(buff, -1);
}
