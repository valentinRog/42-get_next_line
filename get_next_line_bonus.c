/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:22:17 by vrogiste          #+#    #+#             */
/*   Updated: 2022/01/21 18:08:40 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	is_in_str_lst(t_list *lst, char a)
{
	if (!lst)
		return (0);
	if (*(char *)(lst->content) == a)
		return (1);
	return (is_in_str_lst(lst->next, a));
}

void	append_buff_lst(t_list **lst, char *buff, int size)
{
	int		i;
	char	*c;

	i = -1;
	while (++i < size && buff[i])
	{
		c = malloc(1);
		if (!c)
			return ;
		*c = buff[i];
		lst_add_back(lst, lst_new(c));
	}
}

void	cut_str_lst(t_list **lst)
{
	while ((*lst) && *(char *)((*lst)->content) != '\n')
		lst_pop_front(lst);
	lst_pop_front(lst);
}

char	*get_line_lst(t_list *lst)
{
	char	*dst;
	t_list	*head;
	int		i;

	if (!lst)
		return (NULL);
	head = lst;
	i = 0;
	while (lst && i++ >= 0 && *(char *)(lst->content) != '\n')
		lst = lst->next;
	lst = head;
	dst = malloc(i + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (lst && *(char *)(lst->content) != '\n')
	{
		dst[i++] = *(char *)(lst->content);
		lst = lst->next;
	}
	if (lst && *(char *)(lst->content) == '\n')
		dst[i++] = '\n';
	dst[i] = 0;
	return (dst);
}

char	*get_next_line(int fd)
{
	int				bytes_read;
	char			*buff;
	char			*line;
	static t_list	*save[FD_MAX + 1];

	bytes_read = BUFFER_SIZE;
	if (fd > FD_MAX || BUFFER_SIZE < 1)
		return (NULL);
	buff = malloc(BUFFER_SIZE);
	if (!buff)
		return (NULL);
	while (!is_in_str_lst(save[fd], '\n') && bytes_read == BUFFER_SIZE)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		append_buff_lst(&save[fd], buff, bytes_read);
	}
	free(buff);
	line = get_line_lst(save[fd]);
	cut_str_lst(&save[fd]);
	return (line);
}
