/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:26:51 by tjukmong          #+#    #+#             */
/*   Updated: 2023/04/22 02:45:54 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lex_newtoken(t_lex *lex, enum e_tktype type, char *data)
{
	if (!lex->tok)
	{
		lex->tok = malloc(sizeof(t_lextok));
		lex->last_tok = lex->tok;
		lex->tok->t = type;
		lex->tok->data = data;
		lex->tok->next = NULL;
	}
	else
	{
		lex->last_tok->next = malloc(sizeof(t_lextok));
		lex->last_tok = lex->last_tok->next;
		lex->last_tok->t = type;
		lex->last_tok->data = data;
		lex->last_tok->next = NULL;
	}
}

void	lex_ittertoken(t_lex *lex, void (*fn)(t_lextok *tok))
{
	t_lextok	*node;

	if (!lex || !lex->tok || !fn)
		return ;
	node = lex->tok;
	while (node != NULL)
	{
		fn(node);
		node = node->next;
	}
}

// Used for token mapping and insert token inplace of the old one.
// Callback fn returns the last node of the new token stream.
void	lex_maptoken(t_lex *lex, t_lextok *(*fn)(t_lextok *tok))
{
	t_lextok	*node;

	if (!lex || !lex->tok || !fn)
		return ;
	node = lex->tok;
	while (node != NULL)
		node = fn(node)->next;
}

void	lex_cleartoken(t_lex *lex)
{
	t_lextok	**nodes;
	t_lextok	*next;

	if (!lex || !lex->tok)
		return ;
	nodes = &lex->tok;
	while (*nodes != NULL)
	{
		next = (*nodes)->next;
		free((*nodes)->data);
		free((*nodes));
		*nodes = next;
	}
	free(lex->tok);
}

void	lex_insrttoken(t_lextok **tok, t_lextok **newtok)
{
	t_lextok	*first;
	t_lextok	*last;
	t_lextok	*next;

	if (!tok || !*tok || !newtok || !*newtok)
		return ;
	first = *tok;
	last = (*tok)->next;
	next = (*newtok)->next;
	free(first->data);
	first->data = (*newtok)->data;
	first->t = (*newtok)->t;
	while (next != NULL)
		next = next->next;
	next = last;
	first->next = (*newtok)->next;
	free(*newtok);
}
