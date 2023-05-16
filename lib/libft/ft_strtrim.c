/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 22:49:13 by tjukmong          #+#    #+#             */
/*   Updated: 2022/08/31 02:37:42 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Trims the front and the back of a string, using the character sets
// defined in the string *set. Returns a malloc'd string of the resaulting
// trimmed string.

// ft_strtrim("__Hello_World!____", "_!"); returns "Hello_World"

// [__Hello_World!____\0]
//  ~~^                   incrementing the pointer, until no matched set found.

// [__Hello_World!____\0]
//    ~~~ ft_strlen ~~~^  get the string's length at current pointer, len.

// [__Hello_World!____\0]
//    |<- len ->|<~~~~~~  decreasing len until no match found.

// [__Hello_World!____\0]
//    |<strlcpy>|         copy out onto a malloc'd string.

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*res;
	char	*str;
	int		len;

	if (!s1 || !set)
		return (NULL);
	str = (char *)s1;
	while (*str)
	{
		if (ft_strchr(set, *str) == NULL)
			break ;
		str++;
	}
	len = ft_strlen(str);
	while (len)
	{
		if (ft_strchr(set, str[len - 1]) == NULL)
			break ;
		len--;
	}
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, str, len + 1);
	return (res);
}
