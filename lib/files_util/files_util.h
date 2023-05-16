/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_util.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 01:20:57 by tjukmong          #+#    #+#             */
/*   Updated: 2023/04/20 22:46:22 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILES_UTIL_H
# define FILES_UTIL_H

# include "../libft/libft.h"

// Files util
char	*ft_getpwd(void);
char	*ft_pathenv(char *filename, char *env);
char	*ft_getpath(char *filename);

// Files sys
void	ft_chdir(char *dir);

#endif