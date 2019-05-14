/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:47:52 by tamarant          #+#    #+#             */
/*   Updated: 2019/05/08 21:04:50 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "./libft/libft.h"

static int		ft_new_line(const int fd, char **line, char *text, int try)
{
	 int 	len;
	 char	*text_sub;

	 len = 0;
	while (text[len] != '\n' && text[len] != '\0')
		len++;
	text_sub = ft_strdup(ft_strsub(text, len + 1, (ft_strlen(text) - len)));
	if (text[len] == '\n')
	{
		*line = ft_strsub(text, 0, len);
		//printf("%s\n", *line);
		free(text);
		text = NULL;
		text = ft_strdup(text_sub);
	}
	else if (text[len] == '\0')
	{
		if (try == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(text);
		free(text);
		text = NULL;
	}

	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*text;
	char		*text2;
	char		buffer[BUFF_SIZE + 1];
	int			try;

	//проверить на ошибки
	if (fd < 0 || (!line))
		return (-1);
	while ((try = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[try] = '\0';
		//printf("%s\n", buffer);
		if (text == NULL)
			text2 = ft_strdup(buffer);
		else
			text2 = ft_strjoin(text, buffer);
		if (text)
			free(text);
		text = text2;
        if (ft_strchr(buffer, '\n'))
        	break ;
	}

	if (try < 0)
		return (-1);
	if (try == 0 && (text == NULL || text[0] == '\0'))
		return (0);
	/*else
	 {
		 ft_new_line(fd, line, text);
		 return (1);
	 }*/
	return (ft_new_line(fd, line, text, try));
}
