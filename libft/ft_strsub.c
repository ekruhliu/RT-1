/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <ekruhliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:29:39 by ekruhliu          #+#    #+#             */
/*   Updated: 2017/11/15 12:32:04 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*new;
	size_t		i;

	i = 0;
	if (s != NULL)
	{
		new = (char*)malloc(sizeof(char) * len + 1);
		if (new != NULL)
		{
			while (len)
			{
				new[i] = s[start];
				i++;
				start++;
				len--;
			}
			new[i] = '\0';
			return (new);
		}
	}
	return (0);
}
