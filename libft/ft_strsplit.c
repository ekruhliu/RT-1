/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <ekruhliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:41:36 by ekruhliu          #+#    #+#             */
/*   Updated: 2017/11/15 12:46:22 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_super_array(char const *s, char c)
{
	size_t		i;
	size_t		words;
	char		**super_array;

	if (s == NULL)
		return (NULL);
	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if ((s[0] != c && i == 0) || (s[i] != c && s[i - 1] == c))
			words++;
		i++;
	}
	super_array = (char **)malloc(sizeof(char*) * words);
	if (super_array == NULL)
		return (NULL);
	return (super_array);
}

static int		ft_super_array_count_words(char const *s, char c)
{
	int			i;
	int			w;

	if (s == NULL)
		return (0);
	i = 0;
	w = 0;
	while (s[i] != '\0')
	{
		if ((s[0] != c && i == 0) || (s[i] != c && s[i - 1] == c))
			w++;
		i++;
	}
	return (w);
}

static t_pack	varible(void)
{
	t_pack		pack;

	pack.size = 0;
	pack.s_a_p = 0;
	pack.words = 0;
	pack.start = 0;
	pack.i = 0;
	return (pack);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**s_a;
	t_pack		pack;

	pack = varible();
	s_a = ft_super_array(s, c);
	pack.words = ft_super_array_count_words(s, c);
	if (s_a == NULL)
		return (NULL);
	while (s[pack.i])
	{
		while (s[pack.i] == c)
			pack.i++;
		pack.start = pack.i;
		while (s[pack.i] != c && s[pack.i] != '\0')
			pack.i++;
		pack.size = pack.i - pack.start;
		if (pack.words-- != 0)
		{
			s_a[pack.s_a_p] = ft_strsub(s, pack.start, pack.size);
			(s_a[pack.s_a_p] != 0 ? pack.s_a_p += 1 : 0);
		}
	}
	s_a[pack.s_a_p] = 0;
	return (s_a);
}
