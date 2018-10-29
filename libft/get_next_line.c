/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:14:34 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/01/22 13:14:35 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char		*write_to_line(char *line, char *tmp)
{
	size_t			i;
	size_t			len;
	char			*buff;

	len = 0;
	while (tmp[len] != '\n' && tmp[len] != '\0')
		len++;
	buff = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (tmp[i] != '\n' && tmp[i] != '\0')
	{
		buff[i] = tmp[i];
		i++;
	}
	buff[i] = '\0';
	line = ft_strdup(buff);
	free(buff);
	return (line);
}

static	char		*ft_butcher(char *tmp)
{
	size_t			i;
	char			*ptr;

	ptr = tmp;
	i = 0;
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	if (tmp[i] == '\n')
		i = i + 1;
	tmp = ft_strdup(&tmp[i]);
	free(ptr);
	return (tmp);
}

int					get_next_line(const int fd, char **line)
{
	int				size;
	char			buffer[BUFF_SIZE + 1];
	char			*ptr;
	static	char	*tmp[OPEN_MAX];

	size = 1;
	if (fd < 0 || fd > OPEN_MAX || !line || BUFF_SIZE > 8384920)
		return (-1);
	if (tmp[fd] == NULL)
		tmp[fd] = ft_strnew(0);
	while (!ft_strchr(tmp[fd], '\n') && (size = read(fd, buffer, BUFF_SIZE)))
	{
		if (size == -1)
			return (-1);
		buffer[size] = '\0';
		ptr = tmp[fd];
		tmp[fd] = ft_strjoin(ptr, buffer);
		free(ptr);
	}
	*line = write_to_line(*line, tmp[fd]);
	if (tmp[fd][0] == '\0')
		return (0);
	tmp[fd] = ft_butcher(tmp[fd]);
	return (1);
}
