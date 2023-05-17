/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:58:11 by tjukmong          #+#    #+#             */
/*   Updated: 2023/05/17 13:55:21 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_files	*gnl_newfile(t_files *f, int fd)
{
	f = malloc(sizeof(t_files));
	f->b = NULL;
	f->eof = 0;
	f->fin = 0;
	f->fd = fd;
	f->offset = 0;
	f->buff_len = 0;
	f->next = NULL;
	return (f);
}

t_files	*gnl_getfile(int fd)
{
	static t_files	*files;
	t_files			*tmp;

	if (fd < 0 || fd >= FD_MAX)
		return (NULL);
	if (!files)
	{
		files = gnl_newfile(files, fd);
		return (files);
	}
	tmp = files;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	tmp->next = gnl_newfile(files, fd);
	return (tmp->next);
}

void	gnl_free(int fd)
{
	t_files		*file;
	t_buffer	*tmp;

	file = gnl_getfile(fd);
	if (!file)
		return ;
	if (file->eof && file->fin)
	{
		free(file);
		return ;
	}
	file->eof = 1;
	file->fin = 1;
	while (file->b)
	{
		tmp = file->b->next;
		free(file->b);
		if (!tmp)
			break ;
		file->b = tmp;
	}
	free(file);
	file = NULL;
}
