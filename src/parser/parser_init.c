/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:28:42 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/21 19:58:01 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_parser	*parser_init(char **envp, void (*error)(t_parser *parser))
{
	t_parser	*parser;

	parser = malloc(sizeof(t_parser));
	if (!parser)
		error(NULL);
	parser->cmd = cmd_init(error);
	parser->envp = envp;
	parser->path = envp_to_path(envp, error);
	return (parser);
}

char	**envp_to_path(char **envp, void (*error)(t_parser *parser)
{
	char	**path;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_split(envp[i] + 5, ':');
			if (!path)
				error(NULL);
			return (path);
		}
		i++;
	}
	return (NULL);
}

t_cmd	*cmd_init(void (*error)(t_parser *parser)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		error(NULL);
	cmd->token = NULL;
	cmd->arg = NULL;
	cmd->infs = fileset_init(STDIN, error);
	cmd->outfs = fileset_init(STDOUT, error));
	cmd->pipe[0] = -2;
	cmd->pipe[1] = -2;
	cmd->next = NULL;
	return (cmd);
}

t_fileset	*fileset_init(enum e_filetype ft, void (*error)(t_parser *parser)
{
	t_fileset	*fileset;

	fileset = malloc(sizeof(t_fileset));
	if (!fileset)
		error(NULL);
	fileset->name = NULL;
	if (ft == STDIN)
		fileset->fd = 0;
	else if (ft == STDOUT)
		fileset->fd = 1;
	else
	fileset->fd = -2;
	fileset->type = ft;
	fileset->next = NULL;
	return (fileset);
}
