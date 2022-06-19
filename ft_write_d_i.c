/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 09:31:52 by loui              #+#    #+#             */
/*   Updated: 2021/10/27 23:20:31 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_int_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n = -n;
	}
	while (n >= 1)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_write_d_i(int n)
{
	int		remainder;
	char	digit;
	int		len;

	len = ft_int_len(n);
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
	}
	if (n > 9)
	{
		remainder = n % 10;
		ft_write_d_i(n / 10);
		digit = remainder + '0';
		write(1, &digit, 1);
	}
	else
	{
		digit = n + '0';
		write(1, &digit, 1);
	}
	return (len);
}
