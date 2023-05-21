/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:26:35 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/21 20:06:55 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_parser	*parser(char **toklist, char **envp,
	void (*error)(t_parser *parser)
{
	t_parser	*parser;
	t_cmd		*cmd;
	int			i;

	parser = parser_init(envp, error);
	i = -1;
	while (toklist[++i])
		i += token_convert(toklist[i], parser, error);
	cmd = parser->cmd;
	while (cmd->next)
	{
		cmd->arg = token_to_arg(cmd->token, parser, error);
		cmd = cmd->next;
	}
	ft_lstclear(&parser->token, free);
	return (parser);
}
