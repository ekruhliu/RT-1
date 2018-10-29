/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <ekruhliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 18:31:18 by ekruhliu          #+#    #+#             */
/*   Updated: 2017/11/16 15:26:01 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memccpy(void *out, const void *in, int c, size_t n)
{
	unsigned char		*src;
	unsigned char		*dest;
	size_t				i;

	i = 0;
	src = (unsigned char*)in;
	dest = (unsigned char*)out;
	while (n)
	{
		dest[i] = src[i];
		if (src[i] == (unsigned char)c)
		{
			dest[i] = (unsigned char)c;
			return (dest + i + 1);
		}
		i++;
		n--;
	}
	return (NULL);
}
