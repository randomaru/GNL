/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:24:03 by tamarant          #+#    #+#             */
/*   Updated: 2019/05/21 16:38:38 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int 	main(void)
{
	int		fd;
	int		ret;
	char	*one_line;

	 fd = open("file.txt", O_RDONLY);
	 while ((ret = get_next_line(fd, &one_line)))
	 {
	 	if (ret > 0)
		{
	 		printf("%s\n", one_line);
	 		free(one_line);
		}
	 	if (ret == -1)
		{
	 		printf("File does not exist.");
	 		break;
		}
	 }
	 return (0);
}