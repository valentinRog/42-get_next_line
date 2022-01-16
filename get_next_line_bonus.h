/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:50:38 by vrogiste          #+#    #+#             */
/*   Updated: 2022/01/13 17:35:45 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# define FD_MAX 255

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);

t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *neww);
t_list	*ft_lstnew(void *data);
int		ft_lstsize(t_list *lst);
void	ft_pop_front(t_list **head);
void	append_buff_lst(t_list **lst, char *buff, int size);
char	*get_str(t_list *lst);

int		is_in_str_lst(t_list *lst, char a);

#endif
