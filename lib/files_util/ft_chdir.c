/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 08:03:40 by tjukmong          #+#    #+#             */
/*   Updated: 2023/04/20 22:46:49 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "files_util.h"

void	ft_chdir(char *dir)
{
	char	*home;
	char	*substr;
	char	*join;

	if (*dir == '~')
	{
		home = ft_pathenv("", "HOME");
		substr = ft_substr(dir, 1, ft_strlen(dir));
		join = ft_strjoin(home, substr);
		chdir(join);
		free(join);
		free(substr);
		free(home);
		return ;
	}
	chdir(dir);
}
