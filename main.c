#include "get_next_line.h"

void	l(void)
{
	system("leaks a.out");
}

void	ft_puts(char *s)
{
	while (*s)
	{
		write(1, s++, 1);
	}
}

int	main(void)
{
	int	fd;
    char *line;

	atexit(l);
	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_puts(line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}
