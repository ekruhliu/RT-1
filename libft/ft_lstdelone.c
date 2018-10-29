/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <ekruhliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:52:56 by ekruhliu          #+#    #+#             */
/*   Updated: 2017/11/16 14:32:09 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*list;

	list = *alst;
	if (alst != NULL && del != NULL)
	{
		if (list != NULL)
		{
			del(list->content, list->content_size);
			free(list);
			*alst = NULL;
		}
	}
}
