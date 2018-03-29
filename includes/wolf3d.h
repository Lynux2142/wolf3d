/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:05:59 by lguiller          #+#    #+#             */
/*   Updated: 2018/03/29 13:35:06 by bede-fre         ###   ########.fr       */
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
	int			line;
}				t_parse;

void		ft_check_map(char *buff, char *start);
void		ft_read_file(char *name, char ***map);
void		ft_free_map(char **map);

#endif
