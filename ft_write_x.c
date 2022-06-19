/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 08:39:54 by loui              #+#    #+#             */
/*   Updated: 2021/10/28 00:17:36 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_n_less_16(unsigned long n)
{
	int		remainder;
	char	digit;
	int		len;

	if (n < 10)
	{
		digit = n + '0';
		write(1, &digit, 1);
	}
	else if (n < 16)
	{
		n += 87;
		write(1, &n, 1);
	}
	return (1);
}

int	ft_n_grter_16(unsigned long n)
{
	int		remainder;
	char	digit;
	int		len;

	len = n;
	if (n >= 16)
	{
		remainder = n % 16;
		ft_n_grter_16(n / 16);
		if (remainder > 9)
			digit = remainder + 87;
		else
			digit = remainder + '0';
		write(1, &digit, 1);
	}
	else
	{
		ft_n_less_16(n);
	}
	return (ft_hexa_len(len));
}

int	ft_write_x(unsigned int n)
{
	n = (unsigned int)n;
	if (n < 16)
		return (ft_n_less_16(n));
	if (n >= 16)
		return (ft_n_grter_16(n));
	return (0);
}
