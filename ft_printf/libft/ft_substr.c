/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 11:48:46 by gsemerar          #+#    #+#             */
/*   Updated: 2022/01/19 17:21:47 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	size_t	dim;

	if (!s)
		return (NULL);
	dim = ft_strlen(s);
	if (start >= dim)
		start = dim;
	if (start + len >= dim)
		len = dim - start;
	new_str = (char *)malloc(len + 1);
	if (!new_str)
		return (NULL);
	i = start;
	j = 0;
	while (i < dim && j < len)
		new_str[j++] = s[i++];
	new_str[j] = '\0';
	return (new_str);
}
