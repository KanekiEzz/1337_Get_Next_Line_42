/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 04:19:58 by iezzam            #+#    #+#             */
/*   Updated: 2024/11/14 00:33:55 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static char	*_strjoin_save(char **_ptr_li_t_save, char *buffer)
{
	char	*save_ptr_temp;

	save_ptr_temp = ft_strjoin(*_ptr_li_t_save, buffer);
	if (!save_ptr_temp)
	{
		ft_free((void **)&buffer);
		return (NULL);
	}
	return (save_ptr_temp);
}

char *_handel_last_ptr_li_t_save(char **_ptr_li_t_save, size_t count)
{
	char *line;
	if ((*_ptr_li_t_save)[count] == '\0')
	{
		if (count == 0)
			return (NULL);
		line = ft_strdup(*_ptr_li_t_save);
		if (!line)
			return NULL;
		ft_free((void **)_ptr_li_t_save);
		return (line);
	}
	return NULL;
}

char	*_see_line_(char **_ptr_li_t_save)
{
	size_t	count;
	char	*backup;
	char	*line;

	if (!*_ptr_li_t_save)
		return (NULL);
	count = 0;
	while ((*_ptr_li_t_save)[count] && (*_ptr_li_t_save)[count] != '\n')
		count++;
	line = _handel_last_ptr_li_t_save(_ptr_li_t_save, count);
	if (line)
		return line;
	line = ft_substr(*_ptr_li_t_save, 0, count + ((*_ptr_li_t_save)[count] == '\n'));
	if (!line)
		return (ft_free((void **)_ptr_li_t_save), NULL);
	backup = ft_substr(*_ptr_li_t_save, count + 1, ft_strlen(*_ptr_li_t_save) - count - 1);
	if (!backup)
		backup = (free(*_ptr_li_t_save), free(line), NULL);
	ft_free((void **)_ptr_li_t_save);
	if (backup && *backup == '\0')
		ft_free((void **)&backup);
	*_ptr_li_t_save = backup;
	return (line);
}

char	*_ptr_li_t_save_null(char **_ptr_li_t_save, char *buffer)
{
	if (!*_ptr_li_t_save)
	{
		*_ptr_li_t_save = ft_strdup("");
		if (!*_ptr_li_t_save)
		{
			free(buffer);
			return (NULL);
		}
	}
	return (*_ptr_li_t_save);
}

static char	*_read_fd_line(int fd, char *buffer, char **_ptr_li_t_save)
{
	int		read_line;
	char	*save_ptr_temp;

	while (1)
	{
		read_line = read(fd, buffer, BUFFER_SIZE);
		if (read_line <= 0)
			break ;
		buffer[read_line] = '\0';
		if (!_ptr_li_t_save_null(_ptr_li_t_save, buffer))
			return (NULL);
		save_ptr_temp = _strjoin_save(_ptr_li_t_save, buffer);
		if (!save_ptr_temp)
			return (ft_free((void **)&buffer), NULL);
		ft_free((void **)_ptr_li_t_save);
		*_ptr_li_t_save = save_ptr_temp;
		if (ft_strchr(*_ptr_li_t_save, '\n'))
			break ;
	}
	ft_free((void **)&buffer);
	return (_see_line_(_ptr_li_t_save));
}

char	*get_next_line(int fd)
{
	char		*line_ptr;
	char		*buffer;
	static char	*_ptr_li_t_save = NULL;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line_ptr = _read_fd_line(fd, buffer, &_ptr_li_t_save);
	return (line_ptr);
}
