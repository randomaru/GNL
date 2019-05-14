/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 21:31:24 by tamarant          #+#    #+#             */
/*   Updated: 2019/05/08 21:36:06 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include "./libft/libft.h"

int 	main(void)
{
	char *text = "abc\ncde";
	char *text_sub;
	int len;

	len = 0;
	printf("%s\n", text);
	while (text[len] != '\n')
		len++;
	text_sub = ft_strdup(ft_strsub(text, len + 1, (ft_strlen(text) - len)));
	//printf("len_text = %lu\n", ft_strlen(text));
	printf("sub = %s\n", text_sub);
	return (0);
}