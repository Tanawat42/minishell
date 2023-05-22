/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 01:09:28 by tjukmong          #+#    #+#             */
/*   Updated: 2023/05/22 13:27:50 by tjukmong         ###   ########.fr       */
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

void	token_insrt(t_toklist **tok, t_toklist **newtok)
{
	t_toklist	*first;
	t_toklist	*last;
	t_toklist	*next;

	if (!tok || !*tok || !newtok || !*newtok)
		return ;
	first = *tok;
	last = (*tok)->next;
	next = (*newtok)->next;
	// free(first->tok);
	first->tok = (*newtok)->tok;
	first->type = (*newtok)->type;
	while (next != NULL)
		next = next->next;
	next = last;
	first->next = (*newtok)->next;
	free(*newtok);
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
			break ;
		node = tmp->next;
	}
}
