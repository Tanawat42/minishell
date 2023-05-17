/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 01:49:49 by tjukmong          #+#    #+#             */
/*   Updated: 2022/09/25 06:02:10 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// It loops through the list *lst, and then runs function f for every
// element in that list, and then returns the pointer to the data
// to be added to a new list. Basically like JS's map functon
// Clears the list when failed to add new list to the resaultant
// list.

// Example:
//	{content: 123, next:0xXXXXXXXXXXXXXXX } ->
//	{content: 456, next:0xXXXXXXXXXXXXXXX } ->
//	{content: 69, next:0xXXXXXXXXXXXXXXX } ->
//	{content: 420, next:0xXXXXXXXXXXXXXXX }

//	applies function f to the contents :)
//	void	*f(void *element)
//	{
//		return (void *)((int)element * 2);
//	}

// Resaultant list:
//	{content: 246, next:0xXXXXXXXXXXXXXXX } ->
//	{content: 912, next:0xXXXXXXXXXXXXXXX } ->
//	{content: 138, next:0xXXXXXXXXXXXXXXX } ->
//	{content: 840, next:0xXXXXXXXXXXXXXXX }

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*new_lst;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	res = new_lst;
	while (lst -> next)
	{
		new_lst = ft_lstnew(f(lst->next->content));
		if (!new_lst)
		{
			ft_lstclear(&new_lst, del);
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, new_lst);
		lst = lst -> next;
	}
	return (res);
}
