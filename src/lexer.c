/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:47:56 by tjukmong          #+#    #+#             */
/*   Updated: 2023/06/04 17:01:36 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_toklist	*lexer_split_heredoc(t_toklist *tok)
{
	t_token		tok_new;
	int			indx;
	char		**split;

	tok_new.token = NULL;
	indx = 0;
	split = ft_split_notqoute(tok->tok, "<<");
	while (split[indx])
	{
		if (indx)
			token_push(&tok_new, PIPE, ft_strdup("<<"));
		token_push(&tok_new, IDEN, split[indx]);
		indx++;
	}
	free(split);
	token_insrt(tok, &tok_new);
	return (tok_new.token_last);
}

t_toklist	*lexer_split_pipe(t_toklist *tok)
{
	t_token		tok_new;
	int			indx;
	char		**split;

	tok_new.token = NULL;
	indx = 0;
	split = ft_split_notqoute(tok->tok, "|");
	while (split[indx])
	{
		if (indx)
			token_push(&tok_new, PIPE, ft_strdup("|"));
		token_push(&tok_new, IDEN, split[indx]);
		indx++;
	}
	free(split);
	token_insrt(tok, &tok_new);
	return (tok_new.token_last);
}

t_toklist	*lexer_split_space(t_toklist *tok)
{
	t_token		tok_new;
	int			indx;
	char		**split;

	tok_new.token = NULL;
	indx = 0;
	split = ft_split_notqoute(tok->tok, " ");
	while (split[indx])
	{
		token_push(&tok_new, IDEN, split[indx]);
		indx++;
	}
	free(split);
	token_insrt(tok, &tok_new);
	return (tok_new.token_last);
}

t_toklist	*lexer_trimstr(t_toklist *tok)
{
	char	*tmp;

	tmp = ft_strtrim(tok->tok, "\"\'");
	free(tok->tok);
	tok->tok = tmp;
	return (tok);
}

void	print_token(t_toklist *t)
{
	printf("%s\n", t->tok);
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