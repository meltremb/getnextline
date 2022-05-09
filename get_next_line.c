/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:27:28 by meltremb          #+#    #+#             */
/*   Updated: 2022/05/05 14:58:18 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line.h"

/* read the document and put it in a str until BUFFER_SIZE */
char	*read_fd(int fd, char *doc)
{
	char	*bufferlen;
	int		fdret;

	bufferlen = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!bufferlen)
		return (NULL);
	fdret = 1;
	while (fdret != 0 && !ft_strchr(doc, '\n'))
	{
		fdret = read(fd, bufferlen, BUFFER_SIZE);
		if (fdret == -1)
		{
			free(bufferlen);
			return (NULL);
		}
		bufferlen[fdret] = '\0';
		doc = ft_strjoin(doc, bufferlen);
	}
	free(bufferlen);
	return (doc);
}

char	*get_next_line(int fd)
{
	static char	*doc;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	doc = read_fd(fd, doc);
	if (!doc)
		return (NULL);
	line = get_line(doc);
	doc = delete_first_line(doc);
	return (line);
}
