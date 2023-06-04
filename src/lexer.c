/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:47:56 by tjukmong          #+#    #+#             */
/*   Updated: 2023/06/04 17:36:59 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_token(t_toklist *t)
{
	printf("[%d] %s\n", t->type, t->tok);
	free(t->tok);
}

void	lexer(t_global *g, char *ln)
{
	g->token.token = NULL;
	token_push(&g->token, IDEN, ln);
	token_map(&g->token, lexer_split_heredoc);
	token_map(&g->token, lexer_split_pipe);
	token_map(&g->token, lexer_split_space);
	token_map(&g->token, lexer_trimstr);
	token_ittr(&g->token, print_token);
}