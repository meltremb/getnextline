/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:28:08 by meltremb          #+#    #+#             */
/*   Updated: 2022/05/05 12:02:21 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<stdlib.h>
# include<unistd.h>

# ifndef BUFFER_SIZE
#  define  BUFFER_SIZE
# endif

char	*get_next_line(int fd);
char	*read_fd(int fd, char *doc);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *doc, int endline);
char	*ft_strjoin(char *doc, char *bufferlen);
char	*delete_first_line(char *doc);
char	*get_line(char *doc);

#endif
