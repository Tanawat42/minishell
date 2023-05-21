/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:47:56 by tjukmong          #+#    #+#             */
/*   Updated: 2023/05/21 03:40:25 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	token_push(t_global *g, enum e_token_type type, char *tok)
{
	if (!g->token)
	{
		g->token = malloc(sizeof(t_token));
		g->token_last = g->token;
	}
	else
	{
		g->token_last->next = malloc(sizeof(t_token));
		g->token_last = g->token_last->next;
	}
	g->token_last->next = NULL;
	g->token_last->tok = tok;
	g->token_last->type = type;
}

void	lexer(t_global *g, char *ln)
{
	(void)(g);
	token_push(g, IDEN, ln);
	DEBUG(g->token_last->tok);
}
