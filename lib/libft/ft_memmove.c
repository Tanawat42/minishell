/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 22:45:39 by tjukmong          #+#    #+#             */
/*   Updated: 2022/09/06 02:03:53 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Moves the memory from src to dst.
// if same position, don't move.
// if dest is in the higher position in the memory, copy from back to front to
// avoid overlap.

// [Hello, world!\0        ]
// [ dst ->|     <- orld!\0]

// [        Hello, world!\0]
// [Hello ->       | <- dst]

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*from;
	unsigned char	*to;

	from = (unsigned char *) src;
	to = (unsigned char *) dest;
	if (from == to || n == 0)
		return (dest);
	if (to > from)
	{
		while (n-- > 0)
			to[n] = from[n];
		return (dest);
	}
	ft_memcpy(dest, src, n);
	return (dest);
}
