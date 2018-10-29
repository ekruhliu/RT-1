/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <ekruhliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:16:21 by ekruhliu          #+#    #+#             */
/*   Updated: 2017/11/16 15:31:22 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;

	list = *alst;
	if (alst != NULL && del != NULL)
	{
		while (list)
		{
			del(list->content, list->content_size);
			free(list);
			list = list->next;
		}
		*alst = NULL;
	}
}
