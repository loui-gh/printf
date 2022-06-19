/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:57:03 by loui              #+#    #+#             */
/*   Updated: 2021/10/28 17:59:25 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_len(unsigned long nbr)
{
	size_t	len;

	nbr = (unsigned int)nbr;
	len = 0;
	if (nbr <= 15)
		return (1);
	while (nbr >= 1)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

int	ft_p_len(unsigned long nbr)
{
	size_t	len;

	len = 0;
	if (nbr < 0)
		nbr = -nbr;
	if (nbr <= 15)
		return (1);
	while (nbr >= 1)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}
