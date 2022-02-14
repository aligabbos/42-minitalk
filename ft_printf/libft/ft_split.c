/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:17:13 by gsemerar          #+#    #+#             */
/*   Updated: 2022/01/18 23:33:12 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *s, char c);
static char		*ft_find_word(const char *s, char c);
static size_t	ft_strlen_delimiter(const char *s, char c);
static char		*ft_add_word(const char *s, size_t len);

char	**ft_split(const char *s, char c)
{
	char			**split;
	const char		*word;
	size_t			nwords;
	size_t			i;

	if (!s)
		return (NULL);
	nwords = ft_count_words(s, c);
	split = (char **) malloc(sizeof(char *) * (nwords + 1));
	if (!split)
		return (NULL);
	i = 0;
	word = s;
	while (nwords--)
	{
		word = ft_find_word(word, c);
		split[i++] = ft_add_word(word, ft_strlen_delimiter(word, c));
		word += ft_strlen_delimiter(word, c);
	}
	split[i] = 0;
	return (split);
}

static size_t	ft_count_words(const char *s, char c)
{
	size_t	i;
	size_t	flag;
	size_t	count;

	i = 0;
	flag = 1;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && flag)
		{
			count++;
			flag = 0;
		}
		if (s[i] == c)
			flag = 1;
		i++;
	}
	return (count);
}

static char	*ft_find_word(const char *s, char c)
{
	while (*s)
	{
		if (*s != c)
			return ((char *) s);
		s++;
	}
	return ((char *) s);
}

static size_t	ft_strlen_delimiter(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char	*ft_add_word(const char *s, size_t len)
{
	char	*word;

	word = (char *) malloc(sizeof(char) * (len + 1));
	ft_strlcpy(word, s, len + 1);
	return (word);
}
