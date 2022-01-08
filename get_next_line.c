/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:49:58 by vrogiste          #+#    #+#             */
/*   Updated: 2022/01/08 13:34:09 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*dst;
	char	buff[1];

	dst = malloc(1);
	*dst = '\0';
	while(*buff != '\n' && read(fd, buff, 1))
		dst = append_char(dst, *buff);
	if (!(*dst))
	{
		free(dst);
		return (NULL);
	}
	return (dst);
}
