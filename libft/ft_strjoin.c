/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:22:34 by ekruhliu          #+#    #+#             */
/*   Updated: 2017/11/06 16:22:36 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len_s;
	size_t	i;
	size_t	x;

	if (s1 != NULL && s2 != NULL)
	{
		i = 0;
		x = 0;
		len_s = ft_strlen(s1);
		new = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
		if (new != NULL)
		{
			while (len_s--)
				new[i++] = s1[x++];
			x = 0;
			while (s2[x] != '\0')
				new[i++] = s2[x++];
			new[i] = '\0';
			return (new);
		}
	}
	return (NULL);
}
