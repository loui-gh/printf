/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:10:11 by loui              #+#    #+#             */
/*   Updated: 2021/10/28 17:17:54 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_p(void *ptr)
{
	unsigned long		y;
	unsigned long long	x;

	x = (unsigned long)ptr;
	y = x;
	if (!ptr)
		return (write(1, "0x0", 3));
	write(1, "0x", 2);
	ft_n_grter_16(x);
	return (ft_p_len(y) + 2);
}
