#include "get_next_line.h"
#include <stdio.h>

void l(void)
{
	system("leaks a.out");
}

#include <string.h>

int main(void)
{
	atexit(l);
	int		fd;
	char	*line;
	char	*a;
	fd = open("./txt/text0.txt", O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR);
	printf("\n-----------**********------------\n");
	a = get_next_line(fd);
	// while ((a = get_next_line(fd)) != NULL)
	// {
	// 	printf("\nline: %s\n", a);
	// 	free(a);
	// }
	free(a);
	printf("\n-----------**********------------\n");
	close(fd);
	return (0);

}
