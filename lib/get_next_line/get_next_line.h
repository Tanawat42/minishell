/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:42:31 by tjukmong          #+#    #+#             */
/*   Updated: 2023/05/17 13:38:35 by tjukmong         ###   ########.fr       */
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

typedef struct s_buffer
{
	char			buff[BUFFER_SIZE];
	struct s_buffer	*next;
	size_t			nbyte;
}				t_buffer;

typedef struct s_files
{
	int				fd;
	int				eof;
	int				fin;
	t_buffer		*b;
	t_buffer		*b_last;
	size_t			offset;
	size_t			nl_bytes;
	size_t			buff_len;
	struct s_files	*next;
}				t_files;

char	*get_next_line(int fd);
t_files	*gnl_getfile(int fd);
void	gnl_free(int fd);

char	*ft_readline(char *prompt);

#endif
