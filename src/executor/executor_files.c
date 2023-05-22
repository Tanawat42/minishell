/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:22:09 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/22 11:22:52 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	execute_fileset(t_cmd *cmd, t_fileset *fs)
{
	t_fileset	*infs;
	t_fileset	*outfs;

	infs = check_fs(cmd->infs);
	outfs = check_fs(cmd->outfs);
	if (infs->type != STDIN)
		dup2(infs->fd, STDIN_FILENO);
	if (outfs->type != STDOUT)
		dup2(outfs->fd, STDOUT_FILENO);
	if (infs->type != STDIN && infs->type != PIPE)
		close(infs->fd);
	if (outfs->type != STDOUT && outfs->type != PIPE)
		close(outfs->fd);
	closepipe_exec(cmd, parser);
}

void	closepipe_exec(t_cmd *cmd, t_parser *parser)
{
	t_cmd		*tmp;

	tmp = parser->cmd;
	while (tmp)
	{
		if (tmp->pipe[0] >= 2)
			close(tmp->pipe[0]);
		if (tmp->pipe[1] >= 2)
			close(tmp->pipe[1]);
		closefs(tmp);
		tmp = tmp->next;
	}
}

void	closepipe_main(t_parser *parser)
{
	t_cmd		*tmp;

	tmp = parser->cmd;
	while (tmp)
	{
		if (tmp->pipe[0] >= 2)
			close(tmp->pipe[0]);
		if (tmp->pipe[1] >= 2)
			close(tmp->pipe[1]);
		closefs(tmp);
		tmp = tmp->next;
	}
}

void	closefs(t_cmd *cmd)
{
	t_fileset	*fs;

	fs = cmd->infs;
	while (fs)
	{
		if (fs->type != PIPE && fs->fd > 2)
			close(fs->fd);
		fs = fs->next;
	}
	fs = cmd->outfs;
	while (fs)
	{
		if (fs->type != PIPE && fs->fd > 2)
			close(fs->fd);
		fs = fs->next;
	}
}
