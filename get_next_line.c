/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:49:58 by vrogiste          #+#    #+#             */
/*   Updated: 2022/01/09 11:42:00 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
char	*get_next_line(int fd)
{
	char	*dst;
	char	buff[SIZE + 1];
	
	buff[1] = 0;
	dst = malloc(1);
	*dst = '\0';

	static char *buffs = NULL;
	if (buffs)
		dst = append_buff(dst, buffs);

	while(!is_in_str(buff, '\n') && read(fd, buff, SIZE))
		dst = append_buff(dst, buff);
	if (is_in_str(buff, '\n'))
	{
		if (buffs)
			free(buffs);
		buffs = strdup(get_static(dst));
		dst = strdup(cut_str(dst));
	}
	if (!(*dst))
	{
		free(dst);
		return (NULL);
	}
	return (dst);
}
