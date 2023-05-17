/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:42:45 by tjukmong          #+#    #+#             */
/*   Updated: 2023/05/17 12:27:49 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	read_next(t_files *v)
{
	if (!v->b)
	{
		v->b = malloc(sizeof(t_buffer));
		v->b->next = NULL;
		v->b->nbyte = 0;
		v->b_last = v->b;
	}
	else if (!v->eof)
	{
		v->b_last->next = malloc(sizeof(t_buffer));
		v->b_last = v->b_last->next;
		v->b_last->next = NULL;
		v->b_last->nbyte = 0;
	}
	else
		return ;
	v->buff_len++;
	v->b_last->nbyte = read(v->fd, v->b_last->buff, BUFFER_SIZE);
	if (v->b_last->nbyte == 0)
		v->eof = 1;
}

void	get_nlbyte(t_files *v)
{
	size_t		indx;
	t_buffer	*tok;

	if (!v->b)
		read_next(v);
	if (v->b_last->nbyte == (size_t)-1)
		return ;
	tok = v->b;
	while (tok->nbyte)
	{
		indx = (v->nl_bytes + v->offset) % BUFFER_SIZE;
		if (indx > tok->nbyte - 1)
			return ;
		if (tok->buff[indx] == '\n')
		{
			v->nl_bytes++;
			return ;
		}
		v->nl_bytes++;
		if (indx == BUFFER_SIZE - 1)
		{
			read_next(v);
			tok = tok->next;
		}
	}
}

void	consume_token(t_files *v, char *str)
{
	size_t		indx;
	t_buffer	*ptok;

	indx = 0;
	while (indx < v->nl_bytes)
	{
		str[indx] = v->b->buff[v->offset];
		v->offset++;
		indx++;
		if (v->offset == v->b->nbyte)
		{
			ptok = v->b;
			v->b = v->b->next;
			free(ptok);
			v->offset = 0;
			v->buff_len--;
		}
	}
}

char	*get_next_line(int fd)
{
	t_files	*file;
	char	*str;

	file = gnl_getfile(fd);
	if (file == NULL)
		return (NULL);
	file->nl_bytes = 0;
	get_nlbyte(file);
	if (file->nl_bytes == 0 || file->b->nbyte == (size_t)-1)
	{
		free(file->b);
		file->fin = 1;
		return (NULL);
	}
	str = malloc(file->nl_bytes + 1);
	if (!str)
		return (NULL);
	consume_token(file, str);
	str[file->nl_bytes] = '\0';
	return (str);
}
