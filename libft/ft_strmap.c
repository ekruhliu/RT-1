/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <ekruhliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 14:04:50 by ekruhliu          #+#    #+#             */
/*   Updated: 2017/11/15 12:45:06 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	if (s != NULL)
	{
		len = ft_strlen(s);
		str = (char*)malloc(sizeof(char) * len + 1);
		if (str != NULL)
		{
			while (len)
			{
				str[i] = (*f)(s[i]);
				i++;
				len--;
			}
			str[i] = '\0';
			return (str);
		}
	}
	return (NULL);
}
