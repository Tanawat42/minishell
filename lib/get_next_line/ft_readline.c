/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:34:45 by tjukmong          #+#    #+#             */
/*   Updated: 2023/05/22 01:44:12 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "get_next_line.h"

char	*ft_readline(char *prompt)
{
	char	*str;
	size_t	str_len;

	ft_putstr_fd(prompt, 1);
	str = get_next_line(0);
	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	if (str_len > 0)
		str[str_len - 1] = '\0';
	return (str);
}
