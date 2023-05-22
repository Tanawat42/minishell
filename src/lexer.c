/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:47:56 by tjukmong          #+#    #+#             */
/*   Updated: 2023/05/22 13:29:27 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	token_split_delim(t_token *t, char *ln)
{
	char	**split;
	size_t	indx;

	indx = 0;
	split = ft_split_notqoute(ln, "||");
	if (!split)
		return ;
	while (split[indx])
	{
		if (indx)
			token_push(t, PIPE, ft_strdup("||"));
		if (split[indx][0] != '\0')
			token_push(t, IDEN, split[indx]);
		indx++;
	}
	free(split);
}

t_toklist	*token_split_replace(t_toklist *t)
{
	t_token	new;

	if (t == NULL)
		return (NULL);
	new.token = NULL;
	token_split_delim(&new, t->tok);
	token_insrt(&t, &new.token);
	return (new.token_last);
}

void	lexer(t_global *g, char *ln)
{
	t_token		tok;
	t_toklist	*t;

	(void)(g);
	tok.token = NULL;
	token_push(&tok, IDEN, ln);
	token_map(&tok, token_split_replace);

	t = tok.token;
	while (tok.token)
	{
		printf("%d: %s\n", t->type, t->tok);
		free(tok.token->tok);
		t = t->next;
		free(tok.token);
		tok.token = t;
	}
}
