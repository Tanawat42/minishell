/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:23:53 by tjukmong          #+#    #+#             */
/*   Updated: 2022/09/13 22:35:34 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Converts integer into array or chars (stringify).

// Counts the number's length.
static int	ft_num_length(int n)
{
	int	len;

	len = 1;
	if (n < 0 && len++)
		n = -n;
	while (n > 9 && len++)
		n /= 10;
	return (len);
}

// assign the stringified numbers to malloc'd string.
static void	ft_setchr(char *str, int n, int len)
{
	int	stop;

	stop = 0;
	if (n < 0)
	{
		n = -n;
		stop = 1;
		str[0] = '-';
	}
	while (len > stop)
	{
		str[--len] = '0' + (n % 10);
		n /= 10;
	}
}

// get the number's legth, and malloc the string, then assign it.
char	*ft_itoa(int n)
{
	char	*res;
	int		len;

	if (n == -2147483648)
	{
		res = malloc(12 * sizeof(char));
		if (!res)
			return (NULL);
		res[11] = '\0';
		ft_memcpy(res, "-2147483648", sizeof(char) * 11);
		return (res);
	}
	len = ft_num_length(n);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	ft_setchr(res, n, len);
	return (res);
}
