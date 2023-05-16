/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:44:07 by tjukmong          #+#    #+#             */
/*   Updated: 2023/04/20 22:46:43 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "files_util.h"

char	*ft_getpath(char *filename)
{
	char	*pwd;
	char	*tmp;
	char	*join;

	if (!access(filename, F_OK))
	{
		pwd = ft_getpwd();
		tmp = ft_strjoin(pwd, "/");
		join = ft_strjoin(tmp, filename);
		free(tmp);
		free(pwd);
		return (join);
	}
	return (ft_pathenv(filename, "PATH"));
}
