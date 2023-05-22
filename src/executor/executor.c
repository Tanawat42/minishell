/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:49:37 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/22 10:58:39 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int		executor(t_parser *parser)
{
	t_cmd	*cmd;
	int		status;

	cmd = parser->cmd;
	while (cmd)
	{
		cmd->pid = fork();
		if (cmd->pid == -1)
			return (executor_error("fork failed"));
		if (cmd->pid == 0)
			execute(cmd, parser);
		else
			cmd = cmd->next;
	}
	closepipe_main(parser);
	cmd = parser->cmd;
	while (cmd)
	{
		waitpid(cmd->pid, &status, 0);
		cmd = cmd->next;
	}
	return (WEXITSTATUS(status));
}

void	execute(t_cmd *cmd, t_parser *parser)
{
	execute_fileset(cmd, parser);
	execute_cmdset(cmd, parser);
	execve(cmd->arg[0], cmd->arg, parser->envp);
	exit(errno);
}
