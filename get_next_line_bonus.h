/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:20:29 by vrogiste          #+#    #+#             */
/*   Updated: 2022/01/19 10:09:15 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef FD_MAX
#  define FD_MAX 255
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);

t_list	*lst_last(t_list *lst);
void	lst_add_back(t_list **alst, t_list *neww);
t_list	*lst_new(void *data);
int		lst_size(t_list *lst);
void	lst_pop_front(t_list **head);

#endif
