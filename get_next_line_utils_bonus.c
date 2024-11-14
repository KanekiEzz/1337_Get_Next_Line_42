/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iezzam <iezzam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 05:55:40 by iezzam            #+#    #+#             */
/*   Updated: 2024/11/14 20:22:22 by iezzam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	if (*str == '\0')
		return (0);
	return (1 + ft_strlen(str + 1));
}

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*ptr;
	size_t	len;

	len = (ft_strlen(str) + 1);
	ptr = malloc(len * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *str, int search)
{
	while (*str)
	{
		if (*str == (char)search)
			return ((char *)str);
		str++;
	}
	if (*str == (char)search)
		return ((char *)str);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(size + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	if (size > 0)
	{
		j = 0;
		while (s1[j])
			ptr[i++] = s1[j++];
		j = 0;
		while (s2[j])
			ptr[i++] = s2[j++];
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
