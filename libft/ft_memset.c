/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <ekruhliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 13:41:22 by ekruhliu          #+#    #+#             */
/*   Updated: 2017/11/16 11:03:23 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *ptr, int value, size_t num)
{
	char	*d;

	d = ptr;
	while (num)
	{
		*d = value;
		num--;
		d++;
	}
	return (ptr);
}
