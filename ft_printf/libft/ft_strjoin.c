/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:45:59 by gsemerar          #+#    #+#             */
/*   Updated: 2022/01/18 09:44:18 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	dim;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	dim = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *) malloc(sizeof(char) * dim);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, dim);
	ft_strlcat(str, s2, dim);
	return (str);
}
