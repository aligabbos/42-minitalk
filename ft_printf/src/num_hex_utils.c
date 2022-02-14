/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_hex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:03:07 by gsemerar          #+#    #+#             */
/*   Updated: 2022/02/07 16:11:18 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_padding_zero(t_print *format, unsigned int n);
static int	ft_len_zeros(t_print *format, unsigned int n);
static int	ft_dim_num(unsigned long num, unsigned int base_length);
static char	*ft_hex_prefix_and_padd(t_print *f, unsigned int n, int upper);

char	*ft_hex(t_print *format, unsigned int n, int upper)
{
	char	*hex;
	char	*padding;
	char	*str;

	hex = NULL;
	padding = NULL;
	str = NULL;
	hex = ft_uitoahex(n, upper);
	padding = ft_hex_prefix_and_padd(format, n, upper);
	if (padding && hex)
		str = ft_strjoin(padding, hex);
	else if (!n && format->dot && !format->precision)
	{
		free (hex);
		return (padding);
	}
	else if (!padding && hex)
		return (hex);
	free(padding);
	free(hex);
	return (str);
}

static char	*ft_padding_zero(t_print *format, unsigned int n)
{
	int		len;
	char	*padding;

	len = ft_len_zeros(format, n);
	padding = NULL;
	if (len)
	{
		padding = (char *) malloc(sizeof(char) * (len + 1));
		if (!padding)
			return (NULL);
		ft_memset((void *) padding, '0', len);
		padding[len] = '\0';
	}
	return (padding);
}

static int	ft_len_zeros(t_print *format, unsigned int n)
{
	int	len;

	len = 0;
	if (format->dot && format->precision
		&& format->precision > ft_dim_num(n, ft_strlen(HEX_ALPHA)))
		len += (format->precision - ft_dim_num(n, ft_strlen(HEX_ALPHA)));
	else if (!format->dot && format->zero && format->width
		&& format->width > ft_dim_num(n, ft_strlen(HEX_ALPHA)) + len)
		len += (format->width - ft_dim_num(n, ft_strlen(HEX_ALPHA)) - len);
	return (len);
}

static int	ft_dim_num(unsigned long num, unsigned int base_length)
{
	int	dim;

	dim = 0;
	if (num > base_length - 1)
		dim = ft_dim_num(num / base_length, base_length);
	dim += 1;
	return (dim);
}

static char	*ft_hex_prefix_and_padd(t_print *f, unsigned int n, int upper)
{
	char	*str;
	char	*padding;

	padding = NULL;
	str = NULL;
	padding = ft_padding_zero(f, n);
	if (!n && f->dot && !f->precision)
		return (padding);
	if (f->hashtag && n && upper && padding)
		str = ft_strjoin("0X", padding);
	else if (f->hashtag && n && upper)
		str = ft_strjoin("0X", "");
	else if (f->hashtag && n && !upper && padding)
		str = ft_strjoin("0x", padding);
	else if (f->hashtag && n && !upper)
		str = ft_strjoin("0x", "");
	else
		return (padding);
	free(padding);
	return (str);
}
