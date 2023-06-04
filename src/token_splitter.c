/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_splitter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:10:28 by tjukmong          #+#    #+#             */
/*   Updated: 2023/06/04 17:40:12 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

t_toklist	*lexer_split_heredoc(t_toklist *tok)
{
	t_token		tok_new;
	int			indx;
	char		**split;

	if (tok->type != IDEN)
		return (tok);
	tok_new.token = NULL;
	indx = 0;
	split = ft_split_notqoute(tok->tok, "<<");
	while (split[indx])
	{
		if (indx)
			token_push(&tok_new, HEREDOC, ft_strdup("<<"));
		token_push(&tok_new, IDEN, split[indx]);
		indx++;
	}
	free(split);
	token_insrt(tok, &tok_new);
	return (tok_new.token_last);
}

t_toklist	*lexer_split_redirr_in(t_toklist *tok)
{
	t_token		tok_new;
	int			indx;
	char		**split;

	if (tok->type != IDEN)
		return (tok);
	tok_new.token = NULL;
	indx = 0;
	split = ft_split_notqoute(tok->tok, "<");
	while (split[indx])
	{
		if (indx)
			token_push(&tok_new, REDIRR_IN, ft_strdup("<"));
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

	if (tok->type != IDEN)
		return (tok);
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

	if (tok->type != IDEN)
		return (tok);
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
