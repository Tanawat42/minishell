/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:03:10 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/22 11:03:15 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	execute_cmdset(t_cmd *cmd, t_parser *parser)
{
	char	*new_path;

	new_path = NULL;
	if (ft_strchr(cmd->arg[0], '/'))
	{
		new_path = get_builtin(cmd->arg[0]);
		if (new_path == NULL)
			new_path = get_full_path(cmd->arg[0], parser->path);
	}
	else
		new_path = ft_strdup(cmd->arg[0]);
	free(cmd->arg[0]);
	cmd->arg[0] = new_path;
	file_access(cmd->arg[0], X_OK, parser);
}

char	*get_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "echo") == 0)
		return (ft_strdup("./src/builtin/echo"));
	else if (ft_strcmp(cmd, "cd") == 0)
		return (ft_strdup("./src/builtin/cd"));
	else if (ft_strcmp(cmd, "pwd") == 0)
		return (ft_strdup("./src/builtin/pwd"));
	else if (ft_strcmp(cmd, "export") == 0)
		return (ft_strdup("./src/builtin/export"));
	else if (ft_strcmp(cmd, "unset") == 0)
		return (ft_strdup("./src/builtin/unset"));
	else if (ft_strcmp(cmd, "env") == 0)
		return (ft_strdup("./src/builtin/env"));
	else if (ft_strcmp(cmd, "exit") == 0)
		return (ft_strdup("./src/builtin/exit"));
	else
		return (NULL);
}

char	*get_full_path(char *cmd, char **path)
{
	int		i;
	char	*new_path;
	char	*tmp;

	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		new_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(new_path, X_OK) == 0)
			return (new_path);
		free(new_path);
		i++;
	}
	return (NULL);
}
