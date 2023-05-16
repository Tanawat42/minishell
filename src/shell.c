/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 06:00:48 by tjukmong          #+#    #+#             */
/*   Updated: 2023/04/20 22:48:42 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*path_shorthand(void)
{
	char	*pwd;
	char	*home;
	char	*substr;
	char	*replace;

	pwd = ft_getpwd();
	home = ft_pathenv("", "HOME");
	replace = NULL;
	if (ft_strncmp(home, pwd, ft_strlen(home) - 1) == 0)
	{
		substr = ft_substr(pwd, ft_strlen(home), ft_strlen(pwd));
		if (ft_strlen(substr))
			replace = ft_strjoin("~/", substr);
		else
			replace = ft_strdup("~");
		free(substr);
	}
	free(home);
	if (replace)
	{
		free(pwd);
		return (replace);
	}
	return (pwd);
}

char	*draw_shell(void)
{
	char	*path;
	char	*join;
	char	*join2;
	char	*ret;

	path = path_shorthand();
	join = ft_strjoin("\e[0;33m   Minishell  ", path);
	free(path);
	join2 = ft_strjoin(join, " \033[0m ");
	free(join);
	ret = readline(join2);
	free(join2);
	return (ret);
}
