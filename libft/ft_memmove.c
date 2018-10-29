/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <ekruhliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:28:06 by ekruhliu          #+#    #+#             */
/*   Updated: 2017/11/16 15:25:53 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	unsigned char		*srcs;

	dest = (unsigned char*)dst;
	srcs = (unsigned char*)src;
	if (dest == srcs)
		return (dst);
	if (dest > srcs)
	{
		dest = dest + len - 1;
		srcs = srcs + len - 1;
		while (len > 0)
		{
			*(dest--) = *(srcs--);
			len--;
		}
		return (dst);
	}
	while (len > 0)
	{
		*(dest++) = *(srcs++);
		len--;
	}
	return (dst);
}
