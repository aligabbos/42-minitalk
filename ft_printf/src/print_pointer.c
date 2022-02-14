/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:55:55 by gsemerar          #+#    #+#             */
/*   Updated: 2022/02/08 11:53:26 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_print_ptr_support(t_print *format, char *str);

void	ft_print_ptr(t_print *format)
{
	unsigned long	p;
	char			*str;

	p = va_arg(format->args, unsigned long);
	if (!p)
	{
		ft_print_null_ptr(format);
		return ;
	}
	str = ft_ultoaptr(p);
	if (!str)
		return ;
	else
		ft_print_ptr_support(format, str);
	free(str);
}

void	ft_print_null_ptr(t_print *format)
{
	int		padding_width;

	padding_width = 0;
	if ((size_t) format->width > ft_strlen("0x0"))
		padding_width = format->width - ft_strlen("0x0");
	if (format->dash && format->width)
	{
		format->total_length += write(1, "0x0", ft_strlen("0x0"));
		ft_padding(format, ' ', padding_width);
	}
	else if (!format->dash && format->width)
	{
		ft_padding(format, ' ', padding_width);
		format->total_length += write(1, "0x0", ft_strlen("0x0"));
	}
	else
		format->total_length += write(1, "0x0", ft_strlen("0x0"));
}

static void	ft_print_ptr_support(t_print *format, char *str)
{
	int	padding_width;

	padding_width = 0;
	if ((size_t) format->width > ft_strlen(str))
		padding_width = format->width - ft_strlen(str);
	if (format->dash && format->width)
	{
		format->total_length += write(1, str, ft_strlen(str));
		ft_padding(format, ' ', padding_width);
	}
	else if (!format->dash && format->width)
	{
		ft_padding(format, ' ', padding_width);
		format->total_length += write(1, str, ft_strlen(str));
	}
	else
		format->total_length += write(1, str, ft_strlen(str));
}
