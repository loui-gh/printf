/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_upperx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 08:40:01 by loui              #+#    #+#             */
/*   Updated: 2021/10/28 00:11:32 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_upperx_less_16(unsigned int n)
{
	int		remainder;
	char	digit;

	if (n < 10)
	{
		digit = n + '0';
		write(1, &digit, 1);
	}
	else if (n < 16)
	{
		n += 55;
		write(1, &n, 1);
	}
	return (1);
}

static int	ft_upperx_grter_16(unsigned int n)
{
	int		remainder;
	char	digit;
	int		len;

	len = n;
	if (n >= 16)
	{
		remainder = n % 16;
		ft_upperx_grter_16(n / 16);
		if (remainder > 9)
			digit = remainder + 55;
		else
			digit = remainder + '0';
		write(1, &digit, 1);
	}
	else
	{
		ft_upperx_less_16(n);
	}
	return (ft_hexa_len(len));
}

int	ft_write_upperx(unsigned int n)
{
	n = (unsigned int)n;
	if (n < 16)
		return (ft_upperx_less_16(n));
	if (n >= 16)
		return (ft_upperx_grter_16(n));
	return (-1);
}
