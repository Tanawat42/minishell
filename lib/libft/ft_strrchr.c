/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 04:02:37 by tjukmong          #+#    #+#             */
/*   Updated: 2022/09/13 22:07:39 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Like strchr, but returns the last occurrence instead of the first.

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	len;

	len = ft_strlen(s);
	if (c == 0)
		return ((char *)s + len);
	while (len)
		if (s[--len] == (char)c)
			return ((char *)s + len);
	return (NULL);
}
