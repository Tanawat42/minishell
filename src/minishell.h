/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:27:35 by tjukmong          #+#    #+#             */
/*   Updated: 2023/05/17 15:42:10 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define DEBUG_MODE 0

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/signal.h>
# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line.h"

# if DEBUG_MODE == 1
#  define DEBUG(str) ft_putstr_fd("DEBUG: ", 2);ft_putendl_fd(str, 2)
#  define READLN ft_readline("Debug shell > ")
#  define REPL_HIST(line) (void)(line)
#  define FT_GNL_FREE(fd) gnl_free(fd)
# else
#  define DEBUG(str)
#  define READLN readline("Minishell > ")
#  define REPL_HIST(line) add_history(line)
#  define FT_GNL_FREE(fd)
# endif

typedef struct s_global 
{
	
}	t_global;

void	repl_shell(t_global *g,
	void (*parser)(char *ln), void (*sighandel)(int id));

#endif
