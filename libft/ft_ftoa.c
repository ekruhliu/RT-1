/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 17:08:24 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/10/09 17:08:24 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_shmatok(char *res, char *after_dot)
{
	char	*buff;

	buff = ft_strjoin(res, ".");
	ft_strdel(&res);
	res = ft_strjoin(buff, after_dot);
	ft_strdel(&buff);
	ft_strdel(&after_dot);
	return (res);
}

char			*ft_ftoa(float n)
{
	char	*after_dot;
	char	*res;
	int		ipart;
	float	fpart;

	ipart = (int)n;
	fpart = n - (float)ipart;
	if (fpart < 0)
		fpart *= -1;
	res = ft_itoa(ipart);
	if (fpart == 0)
		return (res);
	ipart = 0;
	while (fpart < 1 && fpart > 0)
	{
		fpart *= 10;
		ipart++;
	}
	after_dot = ft_itoa((int)fpart);
	return (ft_shmatok(res, after_dot));
}
