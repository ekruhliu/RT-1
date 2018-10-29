/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <ekruhliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 12:08:50 by ekruhliu          #+#    #+#             */
/*   Updated: 2017/11/16 11:00:47 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memchr(const void *src, int c, size_t len)
{
	size_t				i;
	unsigned char		*s;

	i = 0;
	s = (unsigned char*)src;
	while (len)
	{
		if (s[i] == (unsigned char)c)
			return (&s[i]);
		i++;
		len--;
	}
	return (NULL);
}
