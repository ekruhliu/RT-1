/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 18:28:43 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/10/26 18:28:44 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

long	load_file_str(char *fname, char **str)
{
	long flen;
	FILE *fp;

	if ((fp = fopen(fname, "r+")) == NULL)
		return (-1);
	fseek(fp, 0, SEEK_END);
	flen = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	if ((*str = malloc((size_t)flen + 1)) == NULL)
		return (-1);
	bzero((void*)*str, flen + 1);
	fread(*str, (size_t)flen, 1, fp);
	fclose(fp);
	return (flen);
}

int		set_rgb(unsigned int r, unsigned int g, unsigned int b)
{
	static int i;

	i = 0;
	i++;
	return ((r << 16) | (g << 8) | b);
}

void	ft_get_image(int *pixels, const char *path)
{
	SDL_Surface		*sur;
	int				i;
	int				size;
	int				k;
	unsigned char	*tmp;

	i = -1;
	size = 512 * 512;
	k = 0;
	sur = IMG_Load(path);
	tmp = (unsigned char*)sur->pixels;
	while (++i < size)
	{
		pixels[i] = get_col_by_i(sur->pixels, k);
		k += 4;
	}
	SDL_FreeSurface(sur);
}
