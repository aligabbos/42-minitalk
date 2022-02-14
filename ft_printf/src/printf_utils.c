/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:41:01 by gsemerar          #+#    #+#             */
/*   Updated: 2022/02/08 11:32:29 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_format(t_print *format, char c)
{
	if (c == 'c')
		ft_print_char(format);
	else if (c == 's')
		ft_print_str(format);
	else if (c == 'p')
		ft_print_ptr(format);
	else if (c == 'd')
		ft_print_digit(format);
	else if (c == 'i')
		ft_print_digit(format);
	else if (c == 'u')
		ft_print_unsigned_digit(format);
	else if (c == 'x')
		ft_print_hex(format, LOWER);
	else if (c == 'X')
		ft_print_hex(format, UPPER);
	else if (c == '%')
		ft_print_percentage(format);
}

void	ft_initialize_format(t_print **format)
{
	t_print	*f;

	f = *format;
	f->width = 0;
	f->precision = 0;
	f->dash = 0;
	f->zero = 0;
	f->dot = 0;
	f->hashtag = 0;
	f->space = 0;
	f->plus = 0;
	f->sign = 0;
	f->null_str = 0;
	f->total_length = 0;
}

void	ft_re_initialize_format(t_print **format)
{
	t_print	*f;

	f = *format;
	f->width = 0;
	f->precision = 0;
	f->dash = 0;
	f->zero = 0;
	f->dot = 0;
	f->hashtag = 0;
	f->space = 0;
	f->plus = 0;
	f->sign = 0;
	f->null_str = 0;
}

void	ft_padding(t_print *format, char c, int len)
{
	while (len)
	{
		format->total_length += write(1, &c, 1);
		len--;
	}
}
