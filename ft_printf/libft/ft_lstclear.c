/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:26:37 by gsemerar          #+#    #+#             */
/*   Updated: 2022/01/19 16:09:56 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*start;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	start = (*lst)->next;
	while (start)
	{
		tmp = start->next;
		ft_lstdelone(start, del);
		start = tmp;
	}
	ft_lstdelone(*lst, del);
	*lst = NULL;
}
