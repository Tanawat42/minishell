/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 20:27:27 by tjukmong          #+#    #+#             */
/*   Updated: 2022/08/30 02:03:38 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp_lst;
	int		len;

	tmp_lst = lst;
	len = 0;
	while (tmp_lst)
	{
		tmp_lst = tmp_lst->next;
		len++;
	}
	return (len);
}
