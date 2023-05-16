/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 01:13:51 by tjukmong          #+#    #+#             */
/*   Updated: 2023/04/25 20:36:25 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_token(t_lextok *tok)
{
	if (tok->t == 0)
		printf("token IDEN: ");
	if (tok->t == 1)
		printf("token PIPE: ");
	printf("\"%s\"\n", tok->data);
}

t_lextok	*split_token(t_lextok *tok)
{
	t_lex	new_tok;

	new_tok.tok = NULL;
	if (tok == NULL)
		return (NULL);
	if (ft_strchr(tok->data, '|') == NULL)
		return (tok);
	if (ft_strncmp(tok->data, "|", 2) == 0)
	{
		tok->t = PIPE;
		return (tok);
	}
	lex_splittoken(&new_tok, PIPE, tok->data, "|");
	lex_insrttoken(&tok, &new_tok.tok);
	return (new_tok.last_tok);
}

int	main(void)
{
	t_lex	lex;
	char	*line;

	while (1)
	{
		line = draw_shell();
		if (line == NULL || ft_strncmp(line, "exit", ft_strlen(line)) == 0)
			exit(0);
		debugger("input", line);
		if (*line != '\0')
			add_history(line);
		lex.tok = NULL;
		lex_splittoken(&lex, IDEN, line, " ");
		lex_maptoken(&lex, split_token);
		lex_ittertoken(&lex, print_token);
		lex_cleartoken(&lex);
		free(line);
	}
	rl_clear_history();
	return (0);
}
