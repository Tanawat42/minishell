/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:27:06 by tjukmong          #+#    #+#             */
/*   Updated: 2023/05/17 15:42:52 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_global	g_global;

void	sighandel(int id)
{
	(void)(id);
	DEBUG(strsignal(id));
}

void	parser(char *ln)
{
	(void)(ln);
	DEBUG(ln);
}

int	main(void)
{
	repl_shell(&g_global, parser, sighandel);
}
