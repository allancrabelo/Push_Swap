/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <<aaugusto@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:43:22 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/11 17:54:07 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_read_from_fd(char **stash, int fd)
{
	char	*buffer;
	ssize_t	bytes_read;
	char	*temp;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return ;
	bytes_read = 1;
	while (!ft_strchr(*stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			ft_free(stash);
			break ;
		}
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(*stash, buffer);
		ft_free(stash);
		*stash = temp;
	}
	ft_free(&buffer);
}

char	*ft_extract_line(char **stash)
{
	char	*line;
	char	*temp;
	int		i;

	i = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if ((*stash)[i] == '\n')
		i++;
	line = ft_substr(*stash, 0, i);
	temp = ft_substr(*stash, i, ft_strlen(*stash) - i);
	ft_free(stash);
	*stash = temp;
	if (!line || !*line)
	{
		ft_free(&line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = ft_strjoin("", "");
	if (!stash)
		return (NULL);
	ft_read_from_fd(&stash, fd);
	if (!stash || !*stash)
	{
		ft_free(&stash);
		return (NULL);
	}
	return (ft_extract_line(&stash));
}
