/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:42:31 by tjukmong          #+#    #+#             */
/*   Updated: 2023/04/19 18:09:55 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

# define FD_MAX	1000
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_token
{
	char			buff[BUFFER_SIZE];
	struct s_token	*next;
	size_t			nbyte;
}				t_token;

typedef struct s_vars
{
	int		fd;
	int		eof;
	int		fin;
	t_token	*t;
	t_token	*t_last;
	size_t	offset;
	size_t	nl_bytes;
	size_t	tok_len;
}				t_vars;

char	*get_next_line(int fd);

#endif
