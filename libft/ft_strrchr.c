/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <ekruhliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:30:09 by ekruhliu          #+#    #+#             */
/*   Updated: 2017/11/16 14:20:09 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *str, int c)
{
	size_t	i;
	int		m;
	char	*s;
	char	*x;

	i = 0;
	s = (char*)str;
	m = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			x = &s[i];
			m++;
		}
		i++;
	}
	if (c == '\0')
		return (&s[i]);
	if (m == -1)
		return (NULL);
	return (x);
}
