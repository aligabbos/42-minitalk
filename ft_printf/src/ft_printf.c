/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:30:55 by gsemerar          #+#    #+#             */
/*   Updated: 2022/02/07 16:22:38 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		ret;
	t_print	*format;

	format = (t_print *) malloc(sizeof(t_print));
	if (!format)
		return (-1);
	ft_initialize_format(&format);
	va_start(format->args, str);
	i = -1;
	ret = 0;
	while (str[++i])
	{
		if (str[i] == '%')
			i = ft_check_format(&format, str, i + 1);
		else
			ret += write(1, &str[i], 1);
	}
	va_end(format->args);
	ret += format->total_length;
	free (format);
	return (ret);
}
