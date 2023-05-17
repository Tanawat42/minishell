/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_notqoute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 02:35:08 by tjukmong          #+#    #+#             */
/*   Updated: 2023/04/22 02:43:09 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_splitlen_notqoute(char const *s, char c)
{
	char	*str;
	int		flag;
	int		qoute;
	int		dbqoute;
	size_t	len;

	str = (char *)s;
	len = 0;
	flag = 0;
	qoute = 0;
	dbqoute = 0;
	while (*str)
	{
		if (*str == '\"' && !qoute)
			dbqoute = !dbqoute;
		else if (*str == '\'' && !dbqoute)
			qoute = !qoute;
		if (!(qoute || dbqoute) && *str != c && !flag && ++len)
			flag = 1;
		else if (!(qoute || dbqoute) && *str == c && flag)
			flag = 0;
		str++;
	}
	return (len);
}

static char	**ft_free_arr(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static int	ft_put_table_array(char **res, char *str, size_t *a, size_t *b)
{
	res[*a] = malloc((*b + 1) * sizeof(char));
	if (!res[*a])
	{
		ft_free_arr(res);
		return (1);
	}
	ft_memcpy(res[*a], str - *b, *b);
	res[*a][*b] = '\0';
	(*a)++;
	*b = 0;
	return (0);
}

static char	**ft_put_table(char **res, char *str, char c, size_t len)
{
	size_t	a;
	size_t	b;
	int		qoute;
	int		dbqoute;

	a = 0;
	b = 0;
	qoute = 0;
	dbqoute = 0;
	while (a < len)
	{
		if (*str == '\"' && !qoute)
			dbqoute = !dbqoute;
		else if (*str == '\'' && !dbqoute)
			qoute = !qoute;
		if ((*str && *str != c) || qoute || dbqoute)
			b++;
		else if (b != 0)
			if (ft_put_table_array(res, str, &a, &b))
				return (NULL);
		str++;
	}
	return (res);
}

char	**ft_split_notqoute(char const *s, char c)
{
	char	**res;
	char	*str;
	size_t	len;

	if (!s)
		return (NULL);
	str = (char *)s;
	len = ft_splitlen_notqoute(s, c);
	res = malloc((len + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	res[len] = NULL;
	return (ft_put_table(res, str, c, len));
}
