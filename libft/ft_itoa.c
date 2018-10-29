/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <ekruhliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:41:57 by ekruhliu          #+#    #+#             */
/*   Updated: 2017/11/15 18:44:45 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_size(int n)
{
	int				size;

	size = 0;
	if (n < 0)
	{
		n = -1 * n;
		size++;
	}
	while (n / 10)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

char				*ft_itoa(int n)
{
	char			*result;
	int				size;
	unsigned int	num;

	size = ft_size(n);
	result = (char*)malloc(sizeof(char) * size + 2);
	if (result == NULL)
		return (NULL);
	result[size + 1] = '\0';
	if (n < 0)
		num = -1 * n;
	else
		num = n;
	while (size >= 0)
	{
		result[size] = num % 10 + '0';
		num = num / 10;
		size--;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}
