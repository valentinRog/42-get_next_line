/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:27:17 by vrogiste          #+#    #+#             */
/*   Updated: 2022/01/09 11:28:04 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char	*str)
{
	if (*str && str)
		return (1 + ft_strlen(str + 1));
	return (0);
}

int		is_in_str(char *str, char c)
{
	if (!str || !(*str))
		return (0);
	if (*str == c)
		return (1);
	return (is_in_str(str + 1, c));
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

char	*append_buff(char *str, char *buff)
{
	char	*dst;
	int		i;
	int		j;

	dst = malloc(ft_strlen(str) + ft_strlen(buff) + 1);
	if (!dst)
		return (NULL);
	i = -1;
	while (str[++i])
		dst[i] = str[i];
	j = -1;
	while (buff[++j])
		dst[i++] = buff[j];
	dst[i] = '\0';
	free(str);
	str = dst;
	return (str);
}


char	*get_static(char *str)
{
	while (*str != '\n')
		str++;
	return (str + 1);
}

char	*cut_str(char *str)
{
	char *temp = str;
	while (*str != '\n')
		str++;
	if (*(str + 1))
		*(str + 1) = 0;
	return temp;
}
