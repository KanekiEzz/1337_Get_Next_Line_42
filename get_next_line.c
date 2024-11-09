/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 04:19:58 by iezzam            #+#    #+#             */
/*   Updated: 2024/11/08 17:50:34 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*get_next_line(int fd)
// {
// 	static char	*remainder;
// 	char		buffer[BUFFER_SIZE + 1];
// 	char		*newline_pos;
// 	char		*temp;
// 	ssize_t		bytes_read;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);

// 	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
// 	{
// 		buffer[bytes_read] = '\0';
// 		if (!remainder)
// 			remainder = ft_strdup(buffer);
// 		else
// 		{
// 			temp = ft_strjoin(remainder, buffer);
// 			free(remainder);
// 			remainder = temp;
// 		}
// 		if ((newline_pos = ft_strchr(remainder, '\n')))
// 		{
// 			*newline_pos = '\0';
// 			temp = ft_strdup(remainder);
// 			remainder = ft_strdup(newline_pos + 1);
// 			return (temp);
// 		}
// 	}
// 	if (remainder && *remainder)
// 	{
// 		temp = ft_strdup(remainder);
// 		free(remainder);
// 		remainder = NULL;
// 		return (temp);
// 	}
// 	free(remainder);
// 	remainder = NULL;
// 	return (NULL);
// }

int	main(void)
{
	int fd;
	int fd1;
	int fd2;
	int fd3;
	char *line;

	// Open files with correct mode for creation (read and write permission)
	fd1 = open("./txt/text0.txt", O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR);
	fd = open("./txt/text0.txt", O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR);
	fd2 = open("./txt/text0.txt", O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR);
	fd3 = open("./txt/text2.txt", O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR);

	// Print file descriptors
	printf("%d\n", fd1);
	printf("%d\n", fd);
	printf("%d\n", fd2);
	printf("%d\n", fd3);
	char *a = get_next_line(fd1);
	char *a = get_next_line(fd1);
	// Uncomment and implement get_next_line and ft_strlen functions if needed
	// while ((line = get_next_line(fd)) != NULL)
	// {
	//     write(1, line, ft_strlen(line));
	//     free(line);
	// }

	// Close the file descriptors
	close(fd);
	close(fd1);
	close(fd2);

	printf("------------------------------\n");
	return (0);
}