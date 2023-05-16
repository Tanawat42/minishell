/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:44:07 by tjukmong          #+#    #+#             */
/*   Updated: 2023/04/20 22:45:56 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "files_util.h"

char	*ft_pathenv(char *filename, char *env)
{
	char	*tmp;
	char	*join;
	char	**paths;
	size_t	indx;

	indx = 0;
	paths = ft_split(getenv(env), ':');
	while (*(paths + indx) != NULL)
	{
		tmp = ft_strjoin(*(paths + indx), "/");
		join = ft_strjoin(tmp, filename);
		free(tmp);
		if (!access(join, F_OK))
		{
			while (*(paths + indx) != NULL)
				free(*(paths + indx++));
			free(paths);
			return (join);
		}
		free(join);
		free(*(paths + indx++));
	}
	free(paths);
	return (NULL);
}
