/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 01:09:28 by tjukmong          #+#    #+#             */
/*   Updated: 2023/06/04 16:48:36 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	token_push(t_token *t, enum e_token_type type, char *tok)
{
	if (!t->token)
	{
		t->token = malloc(sizeof(t_toklist));
		t->token_last = t->token;
	}
	else
	{
		t->token_last->next = malloc(sizeof(t_toklist));
		t->token_last = t->token_last->next;
	}
	t->token_last->next = NULL;
	t->token_last->tok = tok;
	t->token_last->type = type;
}

void	token_insrt(t_toklist *dst, t_token *src)
{
	free(dst->tok);
	src->token_last->next = dst->next;
	dst->tok = src->token->tok;
	dst->type = src->token->type;
	dst->next = src->token->next;
	free(src->token);
	src->token = NULL;
}

void	token_ittr(t_token *t, void (*fn)(t_toklist *))
{
	t_toklist	*tok;

	if (!t || !t->token || !t->token->tok || !fn)
		return ;
	tok = t->token;
	while (tok)
	{
		fn(tok);
		tok = tok->next;
	}
}

void	token_map(t_token *t, t_toklist *(*fn)(t_toklist *))
{
	t_toklist	*node;
	t_toklist	*tmp;

	if (!t || !t->token || !t->token->tok || !fn)
		return ;
	node = t->token;
	while (node)
	{
		tmp = fn(node);
		if (!tmp)
			tmp = node;
		node = tmp->next;
	}
}
