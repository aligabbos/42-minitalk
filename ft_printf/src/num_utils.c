/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:03:07 by gsemerar          #+#    #+#             */
/*   Updated: 2022/02/07 16:34:37 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_len_zeros_and_sign(t_print *format, int n);
static char	*ft_padding_zero_and_sign(t_print *format, int n);
static int	ft_dim_num(long num, unsigned int base_length);

char	*ft_ditoa(t_print *format, int n)
{
	char	*num;
	char	*padding;
	char	*str;

	padding = ft_padding_zero_and_sign(format, n);
	num = ft_itoa(n);
	if (!padding && !num)
		return (NULL);
	if (!n && format->dot && !format->precision)
	{
		free(num);
		return (padding);
	}
	if (!padding && num)
		return (num);
	if (n < 0)
		str = ft_strjoin(padding, num + 1);
	else
		str = ft_strjoin(padding, num);
	free(padding);
	free(num);
	return (str);
}

static char	*ft_padding_zero_and_sign(t_print *format, int n)
{
	int		len;
	char	*padding;

	len = ft_len_zeros_and_sign(format, n);
	padding = NULL;
	if (len)
	{
		padding = (char *) malloc(sizeof(char) * (len + 1));
		if (!padding)
			return (NULL);
		padding[0] = '0';
		if (n < 0)
			padding[0] = '-';
		else if (format->plus && n >= 0)
			padding[0] = '+';
		else if (format->space)
			padding[0] = ' ';
		ft_memset((void *) padding + 1, '0', len - 1);
		padding[len] = '\0';
	}
	return (padding);
}

static int	ft_len_zeros_and_sign(t_print *format, int n)
{
	int	len;

	len = 0;
	if (format->plus || format->space || n < 0)
	{
		len += 1;
		format->sign = 1;
	}
	if (format->dot && format->precision
		&& format->precision > ft_dim_num(n, ft_strlen(DECIMAL)))
		len += (format->precision - ft_dim_num(n, ft_strlen(DECIMAL)));
	else if (!format->dot && format->zero && format->width
		&& format->width > ft_dim_num(n, ft_strlen(DECIMAL)) + len)
		len += (format->width - ft_dim_num(n, ft_strlen(DECIMAL)) - len);
	return (len);
}

static int	ft_dim_num(long num, unsigned int base_length)
{
	int	dim;

	dim = 0;
	if (num < 0)
		num = -num;
	if (num > base_length - 1)
		dim = ft_dim_num(num / base_length, base_length);
	dim += 1;
	return (dim);
}
