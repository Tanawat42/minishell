/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_notqoute.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:22:44 by tjukmong          #+#    #+#             */
/*   Updated: 2023/05/21 12:37:07 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_qoute(char c, int *q, int *dbq)
{
	if (c == '\'' && !*q && !*dbq)
		*q = 1;
	else if (c == '\'' && *q)
		*q = 0;
	if (c == '\"' && !*q && !*dbq)
		*dbq = 1;
	else if (c == '\"' && *dbq)
		*dbq = 0;
	if (*q || *dbq)
		return (1);
	return (0);
}

static int	is_matched(char *a, char *b, size_t len, size_t b_len)
{
	if (*a == *b && len >= b_len - 1 && ft_strncmp(a, b, b_len) == 0)
		return (1);
	return (0);
}

char	*strnstr_notqoute(const char *big, const char *little, size_t len)
{
	char	*a;
	char	*b;
	int		q;
	int		dbq;
	size_t	b_len;

	a = (char *)big;
	b = (char *)little;
	q = 0;
	dbq = 0;
	if (a == NULL && len == 0)
		return (NULL);
	if (ft_memcmp(b, (char *)"", 1) == 0)
		return (a);
	b_len = ft_strlen(b);
	if (ft_memcmp(a, (char *)"", 1))
	{
		while (len-- && *a)
		{
			if (!in_qoute(*a, &q, &dbq) && is_matched(a, b, len, b_len))
				return (a);
			a++;
		}
	}
	return (NULL);
}
