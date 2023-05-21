/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:03:38 by tjukmong          #+#    #+#             */
/*   Updated: 2023/05/20 18:59:49 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	repl_shell(t_global *g, void (*fn)(t_global *, char *))
{
	char	*line;

	while (1)
	{
		line = READLN;
		if (!line)
		{
			free(line);
			break ;
		}
		else
			REPL_HIST(line);
		fn(g, line);
		free(line);
	}
	FT_GNL_FREE(0);
}