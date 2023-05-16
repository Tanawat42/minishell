/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 01:20:57 by tjukmong          #+#    #+#             */
/*   Updated: 2023/04/22 04:35:33 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/files_util/files_util.h"

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# define DEBUG 1

enum	e_tktype
{
	IDEN	= 0,
	PIPE	= 1
};

typedef struct s_lextok
{
	enum e_tktype	t;
	char			*data;
	struct s_lextok	*next;
}				t_lextok;

typedef struct s_lex
{
	t_lextok	*tok;
	t_lextok	*last_tok;
	size_t		tok_len;
	int			qoute;
	int			dbqoute;
}				t_lex;

// Debugger tools
void	debugger(char *tag, char *msg);

// Shell TUI
char	*draw_shell(void);

// Lexical analizer
void	lex_newtoken(t_lex *lex, enum e_tktype type, char *data);
void	lex_ittertoken(t_lex *lex, void (*fn)(t_lextok *tok));
void	lex_maptoken(t_lex *lex, t_lextok *(*fn)(t_lextok *tok));
void	lex_cleartoken(t_lex *lex);
void	lex_insrttoken(t_lextok **tok, t_lextok **newtok);

void	lex_splittoken(t_lex *lex, enum e_tktype type, char const *s, char *c);

// void	tokenizer(t_lex *lex, char *str);
// void	split_space_neqstr(t_lex *lex, char *str, size_t *i, size_t *offset);

#endif