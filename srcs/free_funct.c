/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 11:30:00 by lguiller          #+#    #+#             */
/*   Updated: 2018/03/30 10:26:39 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_free_map(char **map)
{
	int	i;

	i = -1;
	while (++i < BUFF_SIZE)
		ft_memdel((void **)&map[i]);
	ft_memdel((void **)&map);
}
