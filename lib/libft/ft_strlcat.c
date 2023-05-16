/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:32:34 by tjukmong          #+#    #+#             */
/*   Updated: 2022/08/29 16:09:55 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	Concatenates string to the destination string, and returns
// the length it tries to concatinate, or concatenated (even if
// it fails to do so).
// 1) Sets the *dst pointer to the length of size.
// 2.1) if the pointer is already at the end of dlen and size limit
// 		is reached, then return dlen + *src's length.
// 2.2) if (2.1) wasn't the case, then copy *src to pointer *dst,
// 		then set nullbyte to terminate the string.

//Ex: 1| char dst[14] = "Hello,";
//	  2| char *src = " world!";
//	  3| size_t len = ft_strlcat(dst, src, 14);
//	  4| printf("\"%s\" %ld", dst, len); // prints: "Hello, world!" 13

// 1) 	Hello,
// 		~~~~~^
// 2)	Hello, world!\0
//		      ~~~~~~~~^

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const char	*odst;
	const char	*osrc;
	size_t		n;
	size_t		dlen;

	odst = dst;
	osrc = src;
	n = size;
	while (n-- > 0 && *dst)
		dst++;
	dlen = dst - odst;
	n = size - dlen;
	if (n-- == 0)
		return (dlen + ft_strlen(src));
	while (*src)
	{
		if (n > 0)
		{
			*dst++ = *src;
			n--;
		}
		src++;
	}
	*dst = '\0';
	return (dlen + (src - osrc));
}
