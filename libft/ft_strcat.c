/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <ekruhliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 10:41:57 by ekruhliu          #+#    #+#             */
/*   Updated: 2017/11/16 12:49:17 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	size_t	i;
	size_t	o;

	i = 0;
	o = 0;
	while (dst[i] != '\0')
		i++;
	while (src[o] != '\0')
	{
		dst[i] = src[o];
		o++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
