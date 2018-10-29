/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 11:05:38 by ekruhliu          #+#    #+#             */
/*   Updated: 2017/10/30 11:05:41 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	o;

	i = 0;
	o = 0;
	while (dst[i])
		i++;
	while (len > 0 && src[o] != '\0')
	{
		dst[i] = src[o];
		o++;
		i++;
		len--;
	}
	dst[i] = '\0';
	return (dst);
}
