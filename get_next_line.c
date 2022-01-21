/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:49:58 by vrogiste          #+#    #+#             */
/*   Updated: 2022/01/21 18:21:43 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static t_list	*lst;
	int				bytes_read;
	char			*buff;
	char			*line;

	bytes_read = BUFFER_SIZE;
	if (BUFFER_SIZE < 1)
		return (NULL);
	buff = malloc(BUFFER_SIZE);
	if (!buff)
		return (NULL);
	while (!is_in_str_lst(lst, '\n') && bytes_read == BUFFER_SIZE)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		append_buff_lst(&lst, buff, bytes_read);
	}
	free(buff);
	line = get_line_lst(lst);
	cut_str_lst(&lst);
	return (line);
}
