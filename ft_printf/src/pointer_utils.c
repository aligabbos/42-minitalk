/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:03:07 by gsemerar          #+#    #+#             */
/*   Updated: 2022/02/07 13:58:50 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_dim_num(unsigned long num, unsigned int base_length);
static int	ft_ntoh(char *hex, unsigned long num, unsigned int bl, char *base);

char	*ft_ultoaptr(unsigned long n)
{
	int		dim;
	char	*char_n;

	dim = ft_dim_num(n, ft_strlen(HEX_ALPHA)) + 3;
	char_n = (char *) malloc(sizeof(char) * dim);
	if (!char_n)
		return (NULL);
	ft_ntoh(char_n, n, ft_strlen(HEX_ALPHA), HEX_ALPHA);
	char_n[0] = '0';
	char_n[1] = 'x';
	char_n[dim - 1] = '\0';
	return (char_n);
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

static int	ft_ntoh(char *hex, unsigned long num, unsigned int bl, char *base)
{
	int	dim;

	dim = 2;
	if (num > bl - 1)
		dim = ft_ntoh(hex, num / bl, bl, base);
	hex[dim] = base[num % bl];
	dim += 1;
	return (dim);
}
