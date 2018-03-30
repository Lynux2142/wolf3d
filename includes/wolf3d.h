/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:05:59 by lguiller          #+#    #+#             */
/*   Updated: 2018/03/30 10:18:41 by lguiller         ###   ########.fr       */
/*   Updated: 2018/03/29 15:03:40 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"

typedef struct	s_parse
{
	char		fd;
	char		*buff;
	short		i;
}				t_parse;

void			ft_check_map(char *buff, char *start);
void			ft_read_file(char *name, char ***map);
void			ft_free_map(char **map);

#endif
