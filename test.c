/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:14:14 by tamarant          #+#    #+#             */
/*   Updated: 2019/05/21 16:38:38 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "get_next_line.h"
#include "./libft/libft.h"
/*
int		main(int argc, char *argv[])
{
	FILE *file;
	int i, b;
	int array[20];
	file = fopen("test.txt", "r");
	if (file == NULL)
	{
		printf("Error");
		exit(0);
	}
	fscanf(file, "%d", &b);
	printf("n = %d\n", b);
	for (i=0; i<b; i++)
	{
		fscanf(file, "%d", &array[i]);
		printf("%d\n", array[i]);
	}
	fclose(file);
	//printf("\n%d %d %d", a,b,c);
	system("PAUSE");
	return (0);
}
*/

static int            ft_new_line(char **text, char **line, int fd, int ret)
{
	char            *tmp;
	int                len;
	len = 0;
	while (text[fd][len] != '\n' && text[fd][len] != '\0')
		len++;
	if (text[fd][len] == '\n')
	{
		*line = ft_strsub(text[fd], 0, len);
		tmp = ft_strdup(text[fd] + len + 1);
		free(text[fd]);
		text[fd] = tmp;
	}
	else if (text[fd][len] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(text[fd]);
		ft_strdel(&text[fd]);
	}
	return (1);
}
int                    get_next_line(const int fd, char **line)
{
	static char        *text[3000];
	char            buf[BUFF_SIZE + 1];
	char            *text2;
	int                ret;
	if (fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (text[fd] == NULL)
			text2 = ft_strdup(buf);
		else
			text2 = ft_strjoin(text[fd], buf);
		free(text[fd]);
		text[fd] = text2;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (text[fd] == NULL || text[fd][0] == '\0'))
		return (0);
	return (ft_new_line(text, line, fd, ret));
}