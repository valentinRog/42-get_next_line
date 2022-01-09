/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:50:38 by vrogiste          #+#    #+#             */
/*   Updated: 2022/01/09 11:39:51 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define SIZE 10 

char	*get_next_line(int fd);

int		ft_strlen(char	*str);
int		is_in_str(char *str, char c);
char	*append_char(char *str, char c);
char	*append_buff(char *str, char *buff);
char	*get_static(char *buff);
char	*cut_str(char *str);

#endif
