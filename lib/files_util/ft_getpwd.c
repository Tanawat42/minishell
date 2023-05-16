/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:44:07 by tjukmong          #+#    #+#             */
/*   Updated: 2023/04/20 22:44:37 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "files_util.h"

char	*ft_getpwd(void)
{
	char	*buff;
	size_t	size;

	buff = ft_calloc(43, 1);
	size = 1;
	while (!getcwd(buff, size * 42))
	{
		free(buff);
		buff = ft_calloc((size * 42) + 1, 1);
		size++;
	}
	return (buff);
}
