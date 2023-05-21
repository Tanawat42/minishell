/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:27:06 by tjukmong          #+#    #+#             */
/*   Updated: 2023/05/21 02:17:42 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_global	g_global;

void	sighandel(int id)
{
	(void)(id);
	DEBUG(strsignal(id));
}

int	main(void)
{
	repl_shell(&g_global, lexer);
	if (!DEBUG_MODE)
		rl_clear_history();
}
