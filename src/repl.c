/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:03:38 by tjukmong          #+#    #+#             */
/*   Updated: 2023/05/17 15:41:03 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	repl_shell(t_global *g,
	void (*parser)(char *ln), void (*sighandel)(int id))
{
	char	*line;

	(void)(g);
	signal(SIGINT, sighandel);
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
		parser(line);
		free(line);
	}
	FT_GNL_FREE(0);
}