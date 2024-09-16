/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:28:48 by paperez-          #+#    #+#             */
/*   Updated: 2024/09/16 13:39:25 by paperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static char	*ft_join(char *text, char *line)
{
	char	*tmp;

	tmp = ft_strjoin(text, line);
	free (text);
	return (tmp);
}

static char	*read_file(int fd, char *text)
{
	char	*buffer;
	int		byte_read;

	if (!text)
	{
		text = ft_calloc(1, sizeof(char));
		text[0] = '\0';
	}
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[byte_read] = 0;
		text = ft_join(text, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free (buffer);
	return (text);
}

static char	*next_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	line = ft_calloc(sizeof(char), i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		line[i + 1] = '\0';
	}
	else
		line[i] = '\0';
	return (line);
}

static char	*rmfirstline(char *buffer)
{
	char	*newbuf;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	j = ft_strlen(buffer);
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	newbuf = ft_calloc(sizeof(char), j - i + 1);
	j = 0;
	i++;
	while (buffer[i] != '\0')
		newbuf[j++] = buffer[i++];
	if (!newbuf)
		return (NULL);
	free (buffer);
	newbuf[j] = '\0';
	return (newbuf);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (0);
	line = next_line(buffer);
	buffer = rmfirstline(buffer);
	return (line);
}

int main()
{
	char *line;
	int fd;
	
	fd = open("prueba.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("fucked");
		return 1;
	}
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (0);
}
