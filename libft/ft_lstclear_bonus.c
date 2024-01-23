/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:20:00 by juestrel          #+#    #+#             */
/*   Updated: 2023/12/07 11:25:38 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;
	t_list	*temp;

	list = *lst;
	while (list != NULL)
	{
		temp = list->next;
		ft_lstdelone(list, del);
		list = temp;
	}
	*lst = NULL;
}
