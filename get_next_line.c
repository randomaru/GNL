/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:47:52 by tamarant          #+#    #+#             */
/*   Updated: 2019/05/20 21:21:03 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*next_symbols(const int fd, char **text, int len)
{
	char *text_sub;

	text_sub = NULL;
	if (text)
	{
		if (len == 0)
			text_sub = ft_strdup(ft_strsub(text[fd], 1,
					ft_strlen(text[fd]) - 1));
		else
			text_sub = ft_strdup(ft_strsub(text[fd], len + 1,
					ft_strlen(text[fd]) - len));
	}
	return (text_sub);
}

static int		ft_new_line(const int fd, char **line, char **text, int read_b)
{
	int		len;
	char	*text_sub;

	len = 0;
	text_sub = NULL;
	while (text[fd][len] != '\n' && text[fd][len] != '\0')
		len++;
	text_sub = next_symbols(fd, text, len);
	if (text[fd][len] == '\n')
	{
		*line = ft_strsub(text[fd], 0, len);
		ft_strdel(&text[fd]);
		text[fd] = ft_strdup(text_sub);
	}
	else if (text[fd][len] == '\0')
	{
		if (read_b == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(text[fd]);
		ft_strdel(&text[fd]);
	}
	free(text_sub);
	return (1);
}

static int		read_text(const int fd, char **line)
{
	static char	*text[MAX_FD];
	char		*text_tmp;
	char		buffer[BUFF_SIZE + 1];
	int			read_bytes;

	text_tmp = NULL;
	while ((read_bytes = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[read_bytes] = '\0';
		if (text[fd] == NULL)
			text_tmp = ft_strdup(buffer);
		else
			text_tmp = ft_strjoin(text[fd], buffer);
		ft_strdel(&text[fd]);
		text[fd] = ft_strdup(text_tmp);
		free(text_tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (read_bytes < 0)
		return (-1);
	if (read_bytes == 0 && (text[fd] == NULL || text[fd][0] == '\0'))
		return (0);
	return (ft_new_line(fd, line, text, read_bytes));
}

int				get_next_line(const int fd, char **line)
{
	if (fd < 0 || (!line) || BUFF_SIZE < 1)
		return (-1);
	return (read_text(fd, line));
}
