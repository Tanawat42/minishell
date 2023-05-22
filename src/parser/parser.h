/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 10:57:29 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/22 09:56:27 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../minishell.h"

enum e_filetype
{
	FILE,
	HEREDOC,
	APPEND,
	PIPE,
	STDIN,
	STDOUT,
};

typedef struct s_fileset
{
	char			*name;
	int				fd;
	enum e_filetype	type;
	t_fileset		*next;
}	t_fileset;

typedef struct s_cmd
{
	t_list		*token;
	char		**arg;
	t_fileset	*infs;
	t_fileset	*outfs;
	int			pipe[2];
	pid_t		pid;
	t_cmd		*next;
}	t_cmd;

typedef struct s_parser
{
	t_cmd	*cmd;
	char	**envp;
	char	**path;
}	t_parser;

// parser.c
/* **************************************************************************
parses toklist in a t_parser struct, splitting each token into related
structures
************************************************************************** */
t_parser	*parser(char **toklist, char **envp,
	void (*error)(t_parser *parser));

// parser_init.c
/* **************************************************************************
initialize a t_parser struct
************************************************************************** */
t_parser	*parser_init(char **envp, void (*error)(t_parser *parser));
/* **************************************************************************
from envp, extract the PATH variable and split it into an array of path
************************************************************************** */
char		**envp_to_path(char **envp, void (*error)(t_parser *parser));
/* **************************************************************************
initialize a t_cmd struct
************************************************************************** */
t_cmd		*cmd_init(void (*error)(t_parser *parser));
/* **************************************************************************
initialize a t_fileset struct
************************************************************************** */
t_fileset	*fileset_init(enum e_filetype ft, void (*error)(t_parser *parser));

// parser_token.c
/* **************************************************************************
converts a token into a corresponding structure, that is
- a t_list node for a generic word
- a t_fileset node for a file ( < << > >> )
- a t_cmd node for a pipe ( | )
************************************************************************** */
int			token_convert(char *token, t_parser *parser, void (*error)(t_parser
	*parser));
/* **************************************************************************
converts a token into a t_cmd node
************************************************************************** */
void		token_to_pipe(t_parser *parser, void (*error)(t_parser *parser));
/* **************************************************************************
converts a t_list node into a char ** array
************************************************************************** */
char		**token_to_arg(t_list *token, t_parser *parser);


// parser_fileset.c
/* **************************************************************************
converts a INFILE token into a t_fileset node
************************************************************************** */
void		infile_to_fileset(char *file, t_cmd *cmd, t_parser *parser, void
	(*error)(t_parser));
/* **************************************************************************
converts a HEREDOC token into a t_fileset node
************************************************************************** */
void		heredoc_to_fileset(char *file, t_cmd *cmd, t_parser *parser, void
	(*error)(t_parser));
/* **************************************************************************
converts a OUTFILE token into a t_fileset node
************************************************************************** */
void		outfile_to_fileset(char *file, t_cmd *cmd, t_parser *parser, void
	(*error)(t_parser));
/* **************************************************************************
converts a APPEND token into a t_fileset node
************************************************************************** */
void		append_to_fileset(char *file, t_cmd *cmd, t_parser *parser, void
	(*error)(t_parser));
/* **************************************************************************
converts a PIPE token into a t_fileset node if there is no other fileset
except STDOUT or STDIN
************************************************************************** */
void		pipe_to_fileset(int fd, t_cmd *cmd, t_parser *parser,
	void (*error)(t_parser));

#endif
