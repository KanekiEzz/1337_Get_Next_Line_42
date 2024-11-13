#include "get_next_line.h"

void	ft_puts(char *s)
{
	while (*s)
	{
		write(1, s++, 1);
	}
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("./txt/text0.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		// write(1, "\n", 1);
		write(1, "(", 1);
		ft_puts(line);
		write(1, ")", 1);
		write(1, "\n", 1);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
