/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <vrogiste@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 12:10:41 by vrogiste          #+#    #+#             */
/*   Updated: 2022/04/09 15:48:56 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	str_append_buff(char **astr, char *buff, size_t n)
{
	char	*dst;
	size_t	i;
	size_t	len;

	if (!astr || !buff || !*buff || !n)
		return ;
	len = str_len(*astr);
	dst = malloc((len + n + 1) * sizeof(char));
	if (dst)
	{
		if (len)
			str_n_cpy(dst, *astr, len);
		i = 0;
		while (i < n)
		{
			dst[len + i] = buff[i];
			i++;
		}
		dst[len + i] = '\0';
	}
	free(*astr);
	*astr = dst;
}

static void	str_n_del_front(char **astr, size_t n)
{
	char	*dst;

	if (!*astr || !n)
		return ;
	n = min(str_len(*astr), n);
	dst = malloc(((str_len(*astr) - n) + 1) * sizeof(char));
	if (dst)
		str_n_cpy(dst, (*astr) + n, str_len((*astr + n)));
	free(*astr);
	if (!*dst)
	{
		free(dst);
		dst = NULL;
	}
	*astr = dst;
}

static char	*get_line(char *str)
{
	char	*ptr;

	if (!str)
		return (NULL);
	ptr = memchr(str, '\n', strlen(str));
	if (!ptr)
		ptr = str + strlen(str);
	return (str_n_dup(str, ptr + 1 - str));
}

static void	cut_line(char **astr)
{
	char	*ptr;

	if (!*astr)
		return ;
	ptr = memchr(*astr, '\n', str_len(*astr));
	if (!ptr)
		ptr = *astr + str_len(*astr);
	str_n_del_front(astr, ptr + 1 - *astr);
}

char	*get_next_line(int fd)
{
	static char	*reminder;
	char		*buff;
	size_t		bytes_read;
	char		*line;

	if (fd < 0)
		str_n_del_front(&reminder, str_len(reminder));
	buff = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buff)
		return (NULL);
	*buff = '\0';
	while (!ft_memchr(reminder, '\n', str_len(reminder)))
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		str_append_buff(&reminder, buff, bytes_read);
		if (bytes_read != BUFFER_SIZE)
			break ;
	}
	line = get_line(reminder);
	cut_line(&reminder);
	free(buff);
	return (line);
}
