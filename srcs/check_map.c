/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 12:40:30 by bede-fre          #+#    #+#             */
/*   Updated: 2018/03/29 15:03:31 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	ft_check_line_length(char *buff)
{
	if (ft_strlen(buff) != BUFF_SIZE)
	{
		ft_putendl_error("error: Wrong line length");
		return (1);
	}
	return (0);
}

static int	ft_check_start(char *buff, short i, char *start)
{
	while (++i < BUFF_SIZE)
	{
		if (buff[i] == 's')
			++start[0];
		if (start[0] > 1)
		{
			ft_putendl_error("error: More than one start");
			return (1);
		}
	}
	return (0);
}

static int	ft_check_char(char *buff, short i)
{
	while (++i < BUFF_SIZE)
		if (buff[i] != ' ' && buff[i] != '1' && buff[i] != 's')
		{
			ft_putendl_error("error: Wrong character found");
			return (1);
		}
	return (0);
}

void		ft_check_map(char *buff, char *start)
{
	short		i;

	i = -1;
	if (ft_check_line_length(buff) || ft_check_start(buff, i, start)
			|| ft_check_char(buff, i))
		exit(1);
}
