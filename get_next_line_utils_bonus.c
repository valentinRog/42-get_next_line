/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:21:20 by vrogiste          #+#    #+#             */
/*   Updated: 2022/01/17 09:21:32 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*lst_last(t_list *lst)
{
	if (!lst)
		return (0);
	if (lst->next)
		return (lst_last(lst->next));
	return (lst);
}

void	lst_add_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (!*alst)
		*alst = new;
	else
	{
		last = lst_last(*alst);
		last->next = new;
	}
}

t_list	*lst_new(void *data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = data;
	node->next = NULL;
	return (node);
}

int	lst_size(t_list *lst)
{
	if (lst)
		return (1 + lst_size(lst->next));
	return (0);
}

void	lst_pop_front(t_list **head)
{
	t_list	*new_head;

	if (!(*head))
		return ;
	new_head = (*head)->next;
	if ((*head)->content)
		free((*head)->content);
	free(*head);
	*head = new_head;
}
