/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:32:28 by loui              #+#    #+#             */
/*   Updated: 2021/10/28 17:15:49 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_print
{
	va_list		args;
	int			count;
	int			i;

}	t_print;

int			ft_putchar_printf(char c);
int			ft_printf(const char *fmt, ...);
int			ft_hexa_len(unsigned long nbr);
int			ft_p_len(unsigned long nbr);
int			ft_putstr_printf(char *s);
int			ft_write_d_i(int n);
int			ft_write_p(void *ptr);
int			ft_write_u(unsigned int n);
int			ft_write_x(unsigned int n);
int			ft_write_upperx(unsigned int n);
int			ft_n_less_16(unsigned long n);
int			ft_n_grter_16(unsigned long n);

#endif