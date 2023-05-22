/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:15:53 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/22 09:22:06 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"


/* ****************************************************************************
Compares 2 strings. Returns the first occurance of the ASCII diffrence of
*str1, and *str2.
**************************************************************************** */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (!*str1 || !*str2 || *str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}
int main(int argc, char **argv)
{
	int		i;
	bool	n_flag;

	i = 1;
	if (ft_strncmp(argv[1], "-n", 2) == 0)
	{
		n_flag = true;
		i++;
	}
	else
		n_flag = false;
	while (i < argc)
	{
		printf("%s", argv[i]);
		if (i < argc - 1)
			printf(" ");
		i++;
	}
	if (!n_flag)
		printf("\n");
	return (0);
}
