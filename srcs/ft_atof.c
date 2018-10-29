/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 13:48:45 by iradchen          #+#    #+#             */
/*   Updated: 2018/03/25 13:48:47 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

float	ft_atof(const char *str)
{
	float	first_part;
	float	second_part;
	int		tens;
	int		sign;

	first_part = ft_atoi(str);
	sign = 1;
	while ((ft_isdigit(*str) && *str))
		str++;
	if (!(*str) || !(*(str + 1)) || *str != '.')
		return (first_part);
	tens = 1;
	str++;
	second_part = ft_atoi(str);
	while (ft_isdigit(*str))
	{
		tens *= 10;
		str++;
	}
	if (first_part < 0)
		sign = -1;
	return (first_part + sign * (second_part / tens));
}
