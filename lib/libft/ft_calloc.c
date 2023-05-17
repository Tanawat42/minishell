/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:04:09 by tjukmong          #+#    #+#             */
/*   Updated: 2022/09/23 16:12:26 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Calloc an array with the nuber of member times the size of
// the type (chat, int, etc.). Returns null if failed to malloc
// or the size is larger than size_t's max value.

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*arr;

	if (nmemb >= SIZE_MAX && size >= SIZE_MAX)
		return (NULL);
	arr = malloc(nmemb * size);
	if (!arr)
		return (NULL);
	ft_bzero(arr, nmemb * size);
	return (arr);
}
