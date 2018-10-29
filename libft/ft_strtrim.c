/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:34:39 by ekruhliu          #+#    #+#             */
/*   Updated: 2017/11/07 15:34:40 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strtrim(char const *s)
{
	size_t			len;
	char			*new;
	size_t			x;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	x = 0;
	len = ft_strlen(s);
	while ((len != 0) && (s[len] == ' ' || s[len] == '\n'
		|| s[len] == '\t' || s[len] == '\0'))
		len--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	new = (char*)malloc(sizeof(char) * ((unsigned int)len - i) + 2);
	if (new == NULL)
		return (NULL);
	while (i <= len && len != 0)
		new[x++] = s[i++];
	new[x] = '\0';
	return (new);
}
