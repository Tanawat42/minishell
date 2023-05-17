/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 20:32:00 by tjukmong          #+#    #+#             */
/*   Updated: 2022/09/13 21:46:05 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

// Finds the substring of *s. Returns the pointer to malloc'd string,
// with the content of *s, starting from start, and end at pointer
// start + len
//
//Ex: 1| char *str = ft_substr("Hello, world!", 5, 4);
//	  2| printf("\"%s\"", str); // prints: "o, w"
//	  3| free(str);

// 1)	"Hello, world!"
// 		~~~~~^			s + start
// 2)	"Hello, world!"
// 			 ~~~^		write "o, w" to res (see ft_strlcpy.c).

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*res;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (len >= s_len - start)
		len = s_len - start;
	if (start > s_len)
	{
		start = s_len;
		len = 0;
	}
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s + start, len + 1);
	return (res);
}
