/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 12:17:06 by tjukmong          #+#    #+#             */
/*   Updated: 2022/08/30 17:50:22 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Itterates through a string, with f as a callback function.

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	indx;

	if (!s || !f)
		return ;
	indx = 0;
	while (s[indx])
	{
		f(indx, s + indx);
		indx++;
	}
}
