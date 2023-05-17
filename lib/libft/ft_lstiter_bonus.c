/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:58:02 by tjukmong          #+#    #+#             */
/*   Updated: 2022/09/25 02:58:50 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// I had to use while (1), because, doing it normally is
// cheating, according to Othelio, apparently >:(
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*node_lst;

	if (!lst || !f)
		return ;
	node_lst = lst;
	while (1)
	{
		f(node_lst->content);
		node_lst = node_lst->next;
		if (!node_lst)
			break ;
	}
}
