/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:12:36 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/21 20:25:40 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	token_convert(char *token, t_parser *parser, void (*error)(t_parser
	*parser))
{
	t_cmd	*cmd;

	cmd = parser->cmd;
	while (cmd->next)
		cmd = cmd->next;
	if (ft_strncmp(token, ">", 1) == 0)
		token_to_fileset(token, parser, error);
	else if (ft_strncmp(token, ">>", 2) == 0)
		token_to_fileset(token, parser, error);
	else if (ft_strncmp(token, "<", 1) == 0)
		token_to_fileset(token, parser, error);
	else if (ft_strncmp(token, "<<", 2) == 0)
		token_to_fileset(token, parser, error);
	else if (ft_strncmp(token, "|", 1) == 0)
		token_to_pipe(parser, error);
	else
		token_arg(token, parser, error);
	if (token[i] == '<' || token[i] == '>')
		return (1);
	return (0);
}
void		token_to_pipe(t_parser *parser, void (*error)(t_parser *parser)
{
	t_cmd		*cmd;
	t_fileset	*fileset;

	cmd = parser->cmd;
	while (cmd->next)
		cmd = cmd->next;
	if (pipe(cmd->pipe) == -1)
		error(parser);
	pipe_to_fileset(cmd->pipe[1], cmd, error);
	cmd = cmd_init(error);
	cmd = cmd->next;
	cmd->infs->next = fileset_init(PIPE, error);
	cmd->infs->next->fd = cmd->pipe[0];
}

char		**token_to_arg(t_list *token, t_parser *parser)
{
	char	**arg;
	int		i;

	i = 0;
	arg = malloc(sizeof(char *) * (ft_lstsize(token) + 1));
	if (!arg)
		error(parser);
	while (token)
	{
		arg[i] = ft_strdup((char *) token->content);
		if (!arg[i])
			error(parser);
		token = token->next;
		i++;
	}
	arg[i] = NULL;
	return (arg);
}
