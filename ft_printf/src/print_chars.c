/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:50:14 by gsemerar          #+#    #+#             */
/*   Updated: 2022/02/08 11:44:45 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_char(t_print *format)
{
	char	c;
	char	sp;

	c = va_arg(format->args, int);
	sp = ' ';
	if (format->dash && format->width)
	{
		format->total_length += write(1, &c, 1);
		ft_padding(format, sp, format->width - 1);
	}
	else if (!format->dash && format->width)
	{
		ft_padding(format, sp, format->width - 1);
		format->total_length += write(1, &c, 1);
	}
	else
		format->total_length += write(1, &c, 1);
}

void	ft_print_str(t_print *format)
{
	char	*str;
	int		padding_width;

	str = va_arg(format->args, char *);
	if (!str)
		str = ft_null_str(format);
	padding_width = ft_calculate_str_padding(format, str);
	if (format->dash && format->width)
	{
		format->total_length += write(1, str, ft_str_length(format, str));
		ft_padding(format, ' ', padding_width);
	}
	else if (!format->dash && format->width)
	{
		ft_padding(format, ' ', padding_width);
		format->total_length += write(1, str, ft_str_length(format, str));
	}
	else
		format->total_length += write(1, str, ft_str_length(format, str));
	if (format->null_str)
		free(str);
}

void	ft_print_percentage(t_print *format)
{
	char	p;
	char	sp;

	p = '%';
	sp = ' ';
	if (format->dash && format->width)
	{
		format->total_length += write(1, &p, 1);
		ft_padding(format, sp, format->width - 1);
	}
	else if (!format->dash && format->width)
	{
		ft_padding(format, sp, format->width - 1);
		format->total_length += write(1, &p, 1);
	}
	else
		format->total_length += write(1, &p, 1);
}
