/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:27:17 by vrogiste          #+#    #+#             */
/*   Updated: 2022/01/08 11:39:58 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char	*str)
{
	if (*str && str)
		return (1 + ft_strlen(str + 1));
	return (0);
}

char	*append_char(char *str, char c)
{
	char	*dst;
	int		i;
	
	dst = malloc(ft_strlen(str) + 2);
	if (!dst)
		return (NULL);
	i = -1;
	while(str[++i])
		dst[i] = str[i];
	dst[i++] = c;
	dst[i] = '\0';
	free(str);
	return (dst);
}
