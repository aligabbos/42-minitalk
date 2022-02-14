/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:55:55 by gsemerar          #+#    #+#             */
/*   Updated: 2022/02/07 16:38:10 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_print_digit_support(t_print *format, char *str);

void	ft_print_digit(t_print *format)
{
	int		n;
	char	*num;

	n = va_arg(format->args, int);
	if (format->dash && format->zero)
		format->zero = 0;
	num = ft_ditoa(format, n);
	if (!num && !format->width)
		return ;
	else
		ft_print_digit_support(format, num);
	free(num);
}

void	ft_print_unsigned_digit(t_print *format)
{
	unsigned int	n;
	char			*num;

	n = va_arg(format->args, unsigned int);
	if (format->dash && format->zero)
		format->zero = 0;
	num = ft_uitoa(format, n);
	if (!num && !format->width)
		return ;
	else
		ft_print_digit_support(format, num);
	free(num);
}

void	ft_print_hex(t_print *format, int upper)
{
	unsigned int	n;
	char			*num;

	n = va_arg(format->args, unsigned int);
	if (format->dash && format->zero)
		format->zero = 0;
	num = ft_hex(format, n, upper);
	if (!num && !format->width)
		return ;
	else
		ft_print_digit_support(format, num);
	free(num);
}

static void	ft_print_digit_support(t_print *format, char *str)
{
	char	sp;

	sp = ' ';
	if (format->dash && ((size_t) format->width > ft_strlen(str)))
	{
		format->total_length += write(1, str, ft_strlen(str));
		ft_padding(format, sp, format->width - ft_strlen(str));
	}
	else if (!format->dash && ((size_t) format->width > ft_strlen(str)))
	{
		ft_padding(format, sp, format->width - ft_strlen(str));
		format->total_length += write(1, str, ft_strlen(str));
	}
	else
		format->total_length += write(1, str, ft_strlen(str));
}
