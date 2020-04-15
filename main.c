#include <stdio.h>
#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	char	*line;

	line = NULL;
	fd = 0;
	fd2 = 0;
	if (argc == 1)
        printf("Usage: %s <filename>\n", argv[0]);
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line) == 1)
		{
            printf("%s\n", line);
			free(line);
		}
		close(fd);
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		while (get_next_line(fd, &line) == 1)
		{
            printf("%s\n", line);
			free(line);
			if (get_next_line(fd2, &line) == 1)
			{
                printf("%s\n", line);
				free(line);
			}
		}
		close(fd);
		close(fd2);
	}
    return (0);
}
