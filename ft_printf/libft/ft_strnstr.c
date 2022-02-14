/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 08:45:36 by gsemerar          #+#    #+#             */
/*   Updated: 2022/01/18 17:50:30 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!(*needle))
		return ((char *) haystack);
	i = 0;
	while (*haystack != '\0' && needle[i] != '\0' && len--)
	{
		if (*haystack == needle[i])
		{
			i++;
		}
		else
		{
			if (i > 0)
			{
				haystack -= i;
				len += i;
			}
			i = 0;
		}
		haystack++;
	}
	if (i > 0 && !needle[i])
		return ((char *) haystack - i);
	return (NULL);
}
