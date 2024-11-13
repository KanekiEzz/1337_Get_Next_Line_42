/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 04:19:58 by iezzam            #+#    #+#             */
/*   Updated: 2024/11/13 02:27:38 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *_strjoin_save(char **_ptr_li_t_save, char *buffer)
{
	char *save_ptr_tmp;

	save_ptr_tmp = ft_strjoin(*_ptr_li_t_save, buffer);
	if (!save_ptr_tmp)
		return (free(buffer), free(*_ptr_li_t_save), NULL);
	return (save_ptr_tmp);
}

char *_see_fine_(char **_ptr_li_t_save)
{
	size_t count;
	char *backup;
	char *line;

	if (!*_ptr_li_t_save)
		return (NULL);
	count = 0;
	while ((*_ptr_li_t_save)[count] && (*_ptr_li_t_save)[count] != '\n')
		count++;
	if ((*_ptr_li_t_save)[count] == '\0')
		return (NULL);
	line = ft_substr(*_ptr_li_t_save, 0, count);
	if (!line)
		return (free(*_ptr_li_t_save), NULL);
	backup = ft_substr(*_ptr_li_t_save, count + 1, ft_strlen(*_ptr_li_t_save) - count - 1);
	if (!backup)
		backup = (free(*_ptr_li_t_save), free(line), NULL);
	free(*_ptr_li_t_save);
	*_ptr_li_t_save = backup;
	return (line);
}

static char *_read_fd_line(int fd, char *buffer, char **_ptr_li_t_save)
{
	int read_line;
	char *save_ptr_tmp;
	char *line_ptr;
	while (1)
	{
		read_line = read(fd, buffer, BUFFER_SIZE);
		if (read_line == -1)
			return (free(buffer), NULL);
		if (read_line == 0)
		{
			if (*_ptr_li_t_save && **_ptr_li_t_save)
			{
				line_ptr = ft_strdup(*_ptr_li_t_save);
				free(*_ptr_li_t_save);
				*_ptr_li_t_save = NULL;
				return (line_ptr);
			}
			break;
		}
		buffer[read_line] = '\0';
		if (!*_ptr_li_t_save)
		{
			*_ptr_li_t_save = ft_strdup("");
			if (!*_ptr_li_t_save)
				return (free(buffer), NULL);
		}
		save_ptr_tmp = _strjoin_save(_ptr_li_t_save, buffer);
		if (!save_ptr_tmp)
			return (free(buffer), NULL);
		free(*_ptr_li_t_save);
		*_ptr_li_t_save = save_ptr_tmp;
		if (_strchr(*_ptr_li_t_save, '\n'))
			break;
	}
	free(buffer);
	line_ptr = _see_fine_(_ptr_li_t_save);
	return (line_ptr);
}

char *get_next_line(int fd)
{
	char *line_ptr;
	char *buffer;
	static char *_ptr_li_t_save = NULL;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line_ptr = _read_fd_line(fd, buffer, &_ptr_li_t_save);
	if (!line_ptr)
		return (NULL);
	return (line_ptr);
}
