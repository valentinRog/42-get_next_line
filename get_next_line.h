/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrogiste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:50:38 by vrogiste          #+#    #+#             */
/*   Updated: 2022/01/09 10:08:31 by vrogiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define SIZE 1

char	*get_next_line(int fd);
char	*gnl(int fd);

int		ft_strlen(char	*str);
char	*append_char(char *str, char c);
char	*append_buff(char *str, char *buff);

#endif
