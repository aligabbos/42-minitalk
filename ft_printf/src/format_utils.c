/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:35:15 by gsemerar          #+#    #+#             */
/*   Updated: 2022/02/07 16:35:01 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_set_flag(t_print *format, char c);
static void	ft_set_width(t_print *format, char c);
static void	ft_set_precision(t_print *format, char c);

int	ft_check_format(t_print **format, const char *str, int index)
{
	ft_re_initialize_format(format);
	while (str[index] != 'c'
		&& str[index] != 's'
		&& str[index] != 'p'
		&& str[index] != 'd'
		&& str[index] != 'i'
		&& str[index] != 'u'
		&& str[index] != 'x'
		&& str[index] != 'X'
		&& str[index] != '%'
		&& str[index] != '\0')
	{
		ft_set_flag(*format, str[index]);
		ft_set_width(*format, str[index]);
		ft_set_precision(*format, str[index]);
		index++;
	}
	ft_print_format(*format, str[index]);
	return (index);
}

static void	ft_set_flag(t_print *format, char c)
{
	if (c == '-')
		format->dash = 1;
	else if (c == '0' && !format->width)
		format->zero = 1;
	else if (c == '.')
		format->dot = 1;
	else if (c == '#')
		format->hashtag = 1;
	else if (c == ' ')
		format->space = 1;
	else if (c == '+')
		format->plus = 1;
}

static void	ft_set_width(t_print *format, char c)
{
	if (format->dot)
		return ;
	if (c >= '0' && c <= '9')
	{
		format->width *= 10;
		format->width += (c - 48);
	}
}

static void	ft_set_precision(t_print *format, char c)
{
	if (format->dot && (c >= '0' && c <= '9'))
	{
		format->precision *= 10;
		format->precision += (c - 48);
	}
}
