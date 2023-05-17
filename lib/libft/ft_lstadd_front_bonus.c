/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:26:07 by tjukmong          #+#    #+#             */
/*   Updated: 2022/08/30 01:27:11 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Points the head reference of new list,
// and sets the old lst's head reference
// to the new list.

// **lst
// --> [head node 1] -> [node 2] -> [node n] -> [ NULL ]
// new_lst->next = *lst;
// [node 0] -> [head node 1] -> [node 2] -> [node n] -> [ NULL ]
// *lst = new_lst
// --> [head node 0] -> [node 1] -> [node 2] -> [node n] -> [ NULL ]

void	ft_lstadd_front(t_list **lst, t_list *new_lst)
{
	if (!lst)
		return ;
	new_lst -> next = *lst;
	*lst = new_lst;
}
