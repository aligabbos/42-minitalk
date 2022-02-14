/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:16:59 by gsemerar          #+#    #+#             */
/*   Updated: 2022/02/07 15:45:29 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_dim_num(unsigned long num, unsigned int base_length);
static int	ft_ntoh(char *hex, unsigned int num, unsigned int bl, char *base);

char	*ft_uitoahex(unsigned int n, int upper)
{
	char	*hex;
	int		dim;

	dim = ft_dim_num(n, ft_strlen(HEX_ALPHA)) + 1;
	hex = (char *) malloc(sizeof(char) * dim);
	if (!hex)
		return (NULL);
	if (upper)
		dim = ft_ntoh(hex, n, ft_strlen(HEX_ALPHA), HEX_ALPHA_UPPER);
	else
		dim = ft_ntoh(hex, n, ft_strlen(HEX_ALPHA), HEX_ALPHA);
	hex[dim] = '\0';
	return (hex);
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

static int	ft_ntoh(char *hex, unsigned int num, unsigned int bl, char *base)
{
	int	dim;

	dim = 0;
	if (num > bl - 1)
		dim = ft_ntoh(hex, num / bl, bl, base);
	hex[dim] = base[num % bl];
	dim += 1;
	return (dim);
}
