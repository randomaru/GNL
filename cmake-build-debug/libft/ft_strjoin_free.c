//
// Created by Twana Amaranth on 2019-05-21.
//

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int opt)
{
	char *res;

	res = ft_strjoin(s1, s2);
	if (opt == 1 || opt > 2)
		free(s1);
	else if (opt >= 2)
		free(s2);
	return (res);
}