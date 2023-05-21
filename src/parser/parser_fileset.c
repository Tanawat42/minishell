/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_fileset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:47:36 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/21 20:20:56 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		infile_to_fileset(char *file, t_cmd *cmd, t_parser *parser, void
	(*error)(t_parser)
{
	t_fileset	*ptr;

	ptr = cmd->infs;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = fileset_init(FILE, error);
	ptr = ptr->next;
	ptr->name = ft_strdup(file);
}

void		heredoc_to_fileset(char *file, t_cmd *cmd, t_parser *parser, void
	(*error)(t_parser))
{
	t_fileset	*ptr;

	ptr = cmd->infs;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = fileset_init(HEREDOC, error);
	ptr = ptr->next;
	ptr->fd = ft_atoi(file);
}

void		outfile_to_fileset(char *file, t_cmd *cmd, t_parser *parser, void
	(*error)(t_parser)))
{
	t_fileset	*ptr;

	ptr = cmd->outfs;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = fileset_init(FILE, error);
	ptr = ptr->next;
	ptr->name = ft_strdup(file);
}

void		append_to_fileset(char *file, t_cmd *cmd, t_parser *parser, void
	(*error)(t_parser))
{
	t_fileset	*ptr;

	ptr = cmd->outfs;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = fileset_init(APPEND, error);
	ptr = ptr->next;
	ptr->name = ft_strdup(file);
}

void		pipe_to_fileset(int fd, t_cmd *cmd, t_parser *parser
	void (*error)(t_parser))
{
	t_fileset	*ptr;

	ptr = cmd->outfs->next;
	cmd->outfs->next = fileset_init(PIPE, error);
	cmd->outfs->next->fd = fd;
	cmd->outfs->next->next = ptr;
}
