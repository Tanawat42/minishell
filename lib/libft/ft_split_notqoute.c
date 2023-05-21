/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_notqoute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 02:35:08 by tjukmong          #+#    #+#             */
/*   Updated: 2023/05/21 14:25:28 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	word_count(char const *s, char *c)
{
	size_t	slen;
	size_t	clen;
	size_t	len;
	char	*str;
	char	*needle;

	str = (char *)s;
	slen = ft_strlen(s);
	clen = ft_strlen(c);
	len = 1;
	while (1)
	{
		needle = strnstr_notqoute(str, c, slen);
		if (needle == NULL)
			break ;
		if (str != needle && needle + clen != s + slen)
			len++;
		str = needle + clen;
	}
	return (len);
}

static void	word_cpy(char const *s, char *c, char **w)
{
	size_t	slen;
	size_t	clen;
	char	*str;
	char	*needle;
	char	*word;

	str = (char *)s;
	slen = ft_strlen(s);
	clen = ft_strlen(c);
	while (str < s + slen)
	{
		needle = strnstr_notqoute(str, c, slen);
		if (needle == NULL)
			needle = (char *)s + slen;
		if (str != needle)
		{
			word = malloc((needle - str) + 1);
			if (word == NULL)
				break ;
			ft_strlcpy(word, str, (needle - str) + 1);
			*w = word;
			w++;
		}
		str = needle + clen;
	}
}

static int	free_if_null(char **s, size_t words)
{
	char	**sp;

	sp = s;
	while (words--)
	{
		if (*sp == NULL)
		{
			sp = s;
			while (*sp)
				free(*sp++);
			free(s);
			return (1);
		}
		sp++;
	}
	return (0);
}

char	**ft_split_notqoute(char const *s, char *c)
{
	size_t	words;
	char	**split;

	if (s == NULL || c == NULL)
		return (NULL);
	words = word_count(s, c);
	split = malloc((words + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split[words] = NULL;
	word_cpy(s, c, split);
	if (free_if_null(split, words))
		return (NULL);
	return (split);
}
