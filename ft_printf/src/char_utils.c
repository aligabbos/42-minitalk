/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:35:24 by gsemerar          #+#    #+#             */
/*   Updated: 2022/02/08 11:33:22 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_calculate_str_padding(t_print *format, char *str)
{
	int	padding_width;

	padding_width = 0;
	if (format->dot && format->precision
		&& (size_t) format->precision < ft_strlen(str)
		&& format->width > format->precision)
		padding_width = format->width - format->precision;
	else if (format->dot && !format->precision)
		padding_width = format->width;
	else if ((size_t) format->width > ft_strlen(str))
		padding_width = format->width - ft_strlen(str);
	return (padding_width);
}

int	ft_str_length(t_print *format, char *str)
{
	if (format->dot && format->precision
		&& (size_t) format->precision < ft_strlen(str))
		return (format->precision);
	else if (format->dot && !format->precision)
		return (0);
	return (ft_strlen(str));
}

char	*ft_null_str(t_print *format)
{
	char	*str;

	str = (char *) malloc(sizeof(char) * ft_strlen("(null)") + 1);
	if (!str)
		return (NULL);
	else
		ft_strlcpy(str, "(null)", ft_strlen("(null)") + 1);
	format->null_str = 1;
	return (str);
}
