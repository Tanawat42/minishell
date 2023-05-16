/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:04:11 by tjukmong          #+#    #+#             */
/*   Updated: 2022/09/06 01:59:53 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns the pointer to a string *big, with the match of the substring
// string *little, with limit n.
// If *little is an empty string, then return the pointer to *big.
// If *big is not an empty string, loop through and find the match.
// If match not found, return NULL.

// ft_strnstr("abcdef", "cde", 6);
//	"abcdef" matched "cde"
//	   ^~~

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*a;
	char	*b;
	size_t	b_len;

	a = (char *)big;
	b = (char *)little;
	if (a == NULL && len == 0)
		return (NULL);
	if (ft_memcmp(b, (char *)"", 1) == 0)
		return (a);
	b_len = ft_strlen(b);
	if (ft_memcmp(a, (char *)"", 1))
	{
		while (len-- && *a)
		{
			if (*a == *b && len >= b_len - 1)
				if (ft_strncmp(a, b, b_len) == 0)
					return (a);
			a++;
		}
	}
	return (NULL);
}
