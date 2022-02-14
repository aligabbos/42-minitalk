/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_unsigned_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:03:07 by gsemerar          #+#    #+#             */
/*   Updated: 2022/02/07 13:57:59 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_utoa(unsigned int n);
static int	ft_len_zeros(t_print *format, unsigned int n);
static char	*ft_padding_zero(t_print *format, unsigned int n);
static int	ft_dim_num(unsigned long num, unsigned int base_length);

char	*ft_uitoa(t_print *format, unsigned int n)
{
	char	*num;
	char	*padding;
	char	*str;

	padding = ft_padding_zero(format, n);
	num = ft_utoa(n);
	if (!padding && !num)
		return (NULL);
	if (!n && format->dot && !format->precision)
	{
		free(num);
		return (padding);
	}
	if (!padding && num)
		return (num);
	str = ft_strjoin(padding, num);
	free(padding);
	free(num);
	return (str);
}

static char	*ft_utoa(unsigned int n)
{
	unsigned long	n_long;
	int				dim;
	char			*cnum;

	n_long = n;
	dim = ft_dim_num(n_long, ft_strlen(DECIMAL));
	cnum = (char *)malloc((dim + 1) * sizeof(char));
	if (!cnum)
		return (NULL);
	cnum[dim] = '\0';
	dim--;
	while (dim >= 0)
	{
		cnum[dim] = (n_long % 10) + '0';
		dim--;
		n_long /= 10;
	}
	return (cnum);
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
		&& format->precision > ft_dim_num(n, ft_strlen(DECIMAL)))
		len += (format->precision - ft_dim_num(n, ft_strlen(DECIMAL)));
	else if (!format->dot && format->zero && format->width
		&& format->width > ft_dim_num(n, ft_strlen(DECIMAL)) + len)
		len += (format->width - ft_dim_num(n, ft_strlen(DECIMAL)) - len);
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
