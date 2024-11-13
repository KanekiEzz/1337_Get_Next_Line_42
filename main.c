#include "get_next_line.h"

void l()
{
	system("leaks a.out");
}


void    ft_puts(char *s)
{
    while (*s)
    {
        write(1, s++, 1);
    }
}

int    main(void)
{
	// atexit(l);
    int        fd;
    // char    *line;

    fd = open("text.txt", O_RDONLY);
    printf("%s\n", get_next_line(fd));
    close(fd);
    printf("%s\n", get_next_line(fd));
    // while (line != NULL)
    // {
    //     // write(1, "\n", 1);
    //     write(1, "(", 1);
    //     ft_puts(line);
    //     free(line);
    //     line = get_next_line(fd);
    // }
    // close(fd);
    return (0);
}