/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:47:52 by tamarant          #+#    #+#             */
/*   Updated: 2019/05/18 20:37:49 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmake-build-debug/libft/libft.h>
#include "get_next_line.h"

static int		ft_new_line(const int fd, char **line, char *text, int read_bytes)
{
	int		len;
	char	*text_sub;

	len = 0;
	if (!text)
		return (0);
	while (text[len] != '\n' && text[len] != '\0')
		len++;
	if (text[len] == '\n')
	{
		text_sub = ft_strdup(ft_strsub(text, len + 1, ft_strlen(text) - len - 1));
		*line = ft_strsub(text, 0, len);
		ft_strdel(&text);
		text = ft_strdup(text_sub);
		//ft_strdel(&text_sub);
	}
	else
	{
		*line = ft_strdup(text);
		
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*text;
	char		*text_tmp;
	char		buffer[BUFF_SIZE + 1];
	int			read_bytes;

	if (fd < 0 || (!line) || BUFF_SIZE < 1)
		return (-1);
	while ((read_bytes = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[read_bytes] = '\0';
		if (text == NULL)
			text_tmp = ft_strdup(buffer);
		else
			text_tmp = ft_strjoin(text, buffer);
		if (text)
			ft_strdel(&text);
		text = ft_strdup(text_tmp);
		//ft_strdel(&text_tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (read_bytes < 0)
		return (-1);
	if (read_bytes == 0  && (text == NULL))
		return (0);
	return (ft_new_line(fd, line, text, read_bytes));
}
