/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:32:25 by tjukmong          #+#    #+#             */
/*   Updated: 2022/09/23 22:30:11 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*curr_lst;

	if (!lst)
		return (NULL);
	curr_lst = lst;
	while (curr_lst->next)
		curr_lst = curr_lst->next;
	return (curr_lst);
}
