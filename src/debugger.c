/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 02:51:22 by tjukmong          #+#    #+#             */
/*   Updated: 2023/04/19 02:59:28 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#if DEBUG == 1

void	debugger(char *tag, char *msg)
{
	ft_putstr_fd(tag, 2);
	ft_putstr_fd(": ", 2);
	if (msg == NULL)
		ft_putstr_fd("(null)", 2);
	ft_putendl_fd(msg, 2);
}
#else

void	debugger(char *tag, char *msg)
{
	(void)(tag);
	(void)(msg);
}
#endif