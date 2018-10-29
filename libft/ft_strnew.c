/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 17:36:25 by ekruhliu          #+#    #+#             */
/*   Updated: 2017/11/03 17:36:26 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*s;

	s = (char*)malloc(sizeof(char) * size + 1);
	if (s == NULL)
		return (NULL);
	ft_memset(s, '\0', size + 1);
	return (s);
}
