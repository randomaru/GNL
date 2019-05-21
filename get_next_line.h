/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:48:31 by tamarant          #+#    #+#             */
/*   Updated: 2019/05/21 20:16:07 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
//# include "./libft/libft.h"
# include <cmake-build-debug/libft/libft.h>
//# include "./cmake-build-debug/libft/libft.a"
# define BUFF_SIZE 8
# define MAX_FD 12000

int		get_next_line(const int fd, char **line);

#endif
