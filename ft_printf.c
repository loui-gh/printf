/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 08:42:02 by loui              #+#    #+#             */
/*   Updated: 2022/03/25 17:06:09 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_faeries(va_list args, char flag)
{
	int	count_arg;

	count_arg = 0;
	if (flag == 'c')
		count_arg += ft_putchar_printf(va_arg(args, int));
	else if (flag == 's')
		count_arg += ft_putstr_printf(va_arg(args, char *));
	else if (flag == 'i' || flag == 'd')
		count_arg += ft_write_d_i(va_arg(args, int));
	else if (flag == 'u')
		count_arg += ft_write_u(va_arg(args, unsigned int));
	else if (flag == 'X')
		count_arg += ft_write_upperx(va_arg(args, unsigned int));
	else if (flag == 'x')
		count_arg += ft_write_x(va_arg(args, unsigned int));
	else if (flag == 'p')
		count_arg += ft_write_p(va_arg(args, void *));
	else if (flag == '%')
		count_arg += ft_putchar_printf(flag);
	return (count_arg);
}

int	ft_printf(char const *fmt, ...)
{
	int		loui;
	t_print	*ptr;

	ptr = (t_print *)malloc(sizeof(t_print));
	va_start(ptr->args, fmt);
	ptr->count = 0;
	ptr->i = 0;
	if (fmt == NULL)
		return (-1);
	while (fmt[ptr->i] != '\0')
	{
		if (fmt[ptr->i] != '%')
			ptr->count += ft_putchar_printf(fmt[ptr->i]);
		else
		{
			ptr->i++;
			ptr->count += ft_faeries(ptr->args, fmt[ptr->i]);
		}
		ptr->i++;
	}
	va_end(ptr->args);
	loui = ptr->count;
	free(ptr);
	return (loui);
}

int	main()
{
	int	c = 2;
	ft_printf("c = %d", c);
	return(0);
}