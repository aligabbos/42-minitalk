/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:39:27 by gsemerar          #+#    #+#             */
/*   Updated: 2022/01/12 16:35:08 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*res1;
	unsigned char	*res2;

	i = 0;
	res1 = (unsigned char *) s1;
	res2 = (unsigned char *) s2;
	if (!n)
		return (0);
	while (i < n)
	{
		if (res1[i] != res2[i])
			return (res1[i] - res2[i]);
		i++;
	}
	return (0);
}
