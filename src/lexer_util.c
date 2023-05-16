/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 23:37:52 by tjukmong          #+#    #+#             */
/*   Updated: 2023/04/22 04:35:34 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lex_splittoken(t_lex *lex, enum e_tktype type, char const *s, char *c)
{
	char	**split;
	size_t	i;

	if (!lex || !s)
		return ;
	split = ft_split_notqoute(s, *c);
	i = 0;
	while (split[i] != NULL)
	{
		if (i && type)
			lex_newtoken(lex, type, ft_strdup(c));
		lex_newtoken(lex, IDEN, split[i]);
		i++;
	}
	free(split);
}
