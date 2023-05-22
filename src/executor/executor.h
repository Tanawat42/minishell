/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:49:29 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/22 11:19:06 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "../parser/parser.h"
# include <errno.h>

/* *****************************************************************************
executes all the commands parsed, and returns the exit status of the last
***************************************************************************** */
int		executor(t_parser *parser);

/* *****************************************************************************
executes a single command
***************************************************************************** */
void	execute(t_cmd *cmd, t_parser *parser);

/* *****************************************************************************
prepare all fileset for execution
- check access for all files
- redriects the final fileset to the correct file descriptor
- closes all file descriptors that are not needed (infile, outfile, pipe)
***************************************************************************** */
void	execute_fileset(t_cmd *cmd, t_fileset *fs);

/* *****************************************************************************
closes all pipes
***************************************************************************** */
void	closepipe_main(t_parser *parser);

/* *****************************************************************************
closes all pipes, but not the ones in the current command
***************************************************************************** */
void	closepipe_exec(t_cmd *cmd, t_parser *parser);

/* *****************************************************************************
closes all file descriptors in the fileset that is not STDIO or PIPE
***************************************************************************** */
void	closefs(t_cmd *cmd);

/* *****************************************************************************
prepare all cmdset for execution
- checks if the command is a builtin
- checks if the command is an alias (no?)
- checks if the command is a path
- checks if the command is an executable
***************************************************************************** */
void	execute_cmdset(t_cmd *cmd, t_parser *parser);

/* *****************************************************************************
checks if the command is a builtin
***************************************************************************** */
char	*get_builtin(char *cmd);

/* *****************************************************************************
checks if the command is a path
***************************************************************************** */
char	*get_full_path(char *cmd, char **path);

#endif
