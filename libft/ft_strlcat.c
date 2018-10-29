/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 11:26:34 by ekruhliu          #+#    #+#             */
/*   Updated: 2017/10/30 11:26:35 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n < ft_strlen(dest))
		return (ft_strlen(src) + n);
	else
	{
		while (dest[i] != '\0')
		{
			i++;
		}
		while ((i < n - 1) && *src)
		{
			dest[i] = *src;
			src++;
			i++;
		}
		dest[i] = '\0';
		return (ft_strlen(dest) + ft_strlen(src));
	}
}
