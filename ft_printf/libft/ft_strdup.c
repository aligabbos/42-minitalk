/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:44:22 by gsemerar          #+#    #+#             */
/*   Updated: 2022/01/17 11:21:02 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, char *src);

char	*ft_strdup(const char *s1)
{
	char	*dest;

	dest = (char *) malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (dest != NULL)
	{
		ft_strcpy(dest, (char *) s1);
		return (dest);
	}
	return (NULL);
}

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}
