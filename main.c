#include "get_next_line.h"

void	l(void)
{
	system("leaks a.out");
}

int	main(void)
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
	printf("%s", get_next_line(fd));
	// fd = open("text.txt", O_RDONLY);
	// printf("%s", get_next_line(fd));
	// while (line != NULL)
	// {
	// 	printf("%s",line);
	// 	free(line);
	// 	line = get_next_line(fd);
	// }
	return (0);
}
