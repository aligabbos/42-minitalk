/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:36:40 by gsemerar          #+#    #+#             */
/*   Updated: 2022/01/19 14:10:56 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_dim_nbr(long n);
static unsigned int	ft_sign(long n);

char	*ft_itoa(int n)
{
	long		n_long;
	long		dim;
	char		*cnum;

	n_long = n;
	dim = ft_dim_nbr(n_long);
	cnum = (char *)malloc((dim + 1) * sizeof(char));
	if (!cnum)
		return (NULL);
	cnum[dim] = '\0';
	dim--;
	if (n_long < 0)
		n_long = -n_long;
	while (dim >= 0)
	{
		cnum[dim] = (n_long % 10) + '0';
		dim--;
		n_long /= 10;
	}
	if (ft_sign(n))
		cnum[0] = '-';
	return (cnum);
}

static unsigned int	ft_dim_nbr(long n)
{
	unsigned int	dim;

	if (n == 0)
		return (1);
	dim = 0;
	if (n < 0)
	{
		dim++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		dim++;
	}
	return (dim);
}

static unsigned int	ft_sign(long n)
{
	if (n < 0)
		return (1);
	return (0);
}
