/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_same_symbol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <ekruhliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:08:29 by ekruhliu          #+#    #+#             */
/*   Updated: 2017/11/15 12:39:04 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_same_symbol(char *s, char l)
{
	size_t	i;
	size_t	symbol;

	i = 0;
	symbol = 0;
	while (s[i])
	{
		if (s[i] == l)
			symbol++;
		i++;
	}
	return (symbol);
}
