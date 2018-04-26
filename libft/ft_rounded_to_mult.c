/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rounded_to_mult.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 09:30:13 by lguiller          #+#    #+#             */
/*   Updated: 2018/04/20 10:15:10 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_roundmsup(int nb, int mult)
{
	while ((nb % mult) != 0)
		++nb;
	return (nb);
}

int		ft_roundminf(int nb, int mult)
{
	while ((nb % mult) != 0)
		--nb;
	return (nb);
}
