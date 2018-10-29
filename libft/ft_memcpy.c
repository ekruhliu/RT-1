/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <ekruhliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:26:08 by ekruhliu          #+#    #+#             */
/*   Updated: 2017/11/16 13:05:01 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memcpy(void *out, const void *in, size_t n)
{
	size_t				i;
	const unsigned char	*inq;
	unsigned char		*o;

	if (out && in)
	{
		i = 0;
		inq = in;
		o = out;
		while (n)
		{
			o[i] = inq[i];
			i++;
			n--;
		}
		return (out);
	}
	else
		return (NULL);
}
