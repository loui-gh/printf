/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 11:08:24 by loflavel          #+#    #+#             */
/*   Updated: 2021/10/28 00:00:52 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_u(unsigned int n)
{
	int		remainder;
	char	digit;

	if (n > 9)
	{
		remainder = n % 10;
		ft_putnbr_u(n / 10);
		digit = remainder + '0';
		write(1, &digit, 1);
	}
	else
	{
		digit = n + '0';
		write(1, &digit, 1);
	}
}

static int	ft_uint_len(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_write_u(unsigned int n)
{
	ft_putnbr_u(n);
	return (ft_uint_len(n));
}
