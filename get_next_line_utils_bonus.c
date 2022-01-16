/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:27:17 by vrogiste          #+#    #+#             */
/*   Updated: 2022/01/13 09:47:19 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	if (lst->next)
		return (ft_lstlast(lst->next));
	return (lst);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (!*alst)
		*alst = new;
	else
	{
		last = ft_lstlast(*alst);
		last->next = new;
	}
}

t_list	*ft_lstnew(void *data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = data;
	node->next = NULL;
	return (node);
}

int	ft_lstsize(t_list *lst)
{
	if (lst)
		return (1 + ft_lstsize(lst->next));
	return (0);
}

void	ft_pop_front(t_list **head)
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
