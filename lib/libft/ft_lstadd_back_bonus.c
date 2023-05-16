/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:25:00 by tjukmong          #+#    #+#             */
/*   Updated: 2022/09/24 16:55:59 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_lst)
{
	t_list	*lst_last;

	if (!lst)
		return ;
	if (*lst)
	{
		lst_last = ft_lstlast(*lst);
		lst_last->next = new_lst;
	}
	else
		*lst = new_lst;
}
