/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 04:19:58 by iezzam            #+#    #+#             */
/*   Updated: 2024/11/09 15:18:52 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*_read_and_append(int fd, char *buffer, char *result)
{
	int		read_line;
	char	*temp;

	read_line = 1;
	while ((read_line = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (read_line == -1)
			return (free(buffer), NULL);
		else if (read_line == 0)
			break ;
		buffer[read_line] = '\0';
		if (!result)
		{
			result = ft_strdup("");
			if (!result)
				return (free(buffer), NULL);
		}
		temp = ft_strjoin(result, buffer);
		free(result);
		result = temp;
		if (!result)
			return (free(buffer), NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (free(buffer), result);
}

static char	*_see_fine_line(char *line)
{
	size_t	count;
	char	*backup;

	count = 0;
	while (line[count] && line[count] != '\n')
		count++;
	if (line[count] == '\0')
		return (NULL);
	backup = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (!backup)
		return (free(line), NULL);
	if (*backup == '\0')
		backup = (free(backup), NULL);
	line[count + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*result = NULL;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	if (!(buffer = malloc(BUFFER_SIZE + 1)))
		return (NULL);
	line = _read_and_append(fd, buffer, result);
	if (!line)
	{
		free(result);
		result = NULL;
		return (NULL);
	}
	printf("result: %s", result);
	printf("\n---------*\nline: \n%s\nresult: %s\n---------*\n", line, result);
	result = _see_fine_line(line);
	printf("\nresult: %s", result);
	return (line);
}
