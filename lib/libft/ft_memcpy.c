/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 22:13:26 by tjukmong          #+#    #+#             */
/*   Updated: 2022/09/04 18:04:33 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*destptr;
	unsigned char	*ptr;

	if (!dest && !src)
		return (NULL);
	destptr = dest;
	ptr = (unsigned char *)src;
	while (n-- > 0)
		*destptr++ = *ptr++;
	return (dest);
}
