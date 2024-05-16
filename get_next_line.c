/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:28:48 by paperez-          #+#    #+#             */
/*   Updated: 2024/05/16 13:31:57 by paperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_join(char *text, char *line)
{
	char	*tmp;

	tmp = ft_strjoin(text, line);
	free(text);
	return(tmp);
}

static char	*read_file(int fd, char *text)
{
	char	*buffer;
	int	byte_read;

	if (!text)
		text = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return(NULL);
		}
		buffer[byte_read] = '\0';
		text = ft_join(text, buffer);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free(buffer);
	return(text);
}

static char	*next_line(char *buffer)
{
	int	i;
	int	j;
	char	*line;

	i = ft_strlen(buffer) + 1;
	j = i;
	while (buffer[j] != '\n' && j > 0)
	{
		j--;
	}
	line = ft_calloc((i - j + 1), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[j] != '\0')
	{
		line[i] = buffer[j];
		i++;
		j++;
	}
	return (line);
}

static char	*rmfirstline(char *buffer, char *line)
{
	int	i;
	int	j;
	char	*newbuf;

	i = 0;
	j = ft_strlen(buffer);
	while(buffer[i] == line[i])
		i++;
	newbuf  = ft_calloc(j - i + 1, sizeof(char));
	j = 0;
	while(buffer && buffer != '\n')
	{
		newbuf[j] = buffer[i];
		i++;
		j++;
	}
	free(buffer);
	return (newbuf);
}

char	*get_next_line(int fd)
{
	char	*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = next_line(buffer);
	buffer = rmfirstline(buffer, line);
	return (line);
}

#include <stdio.h>

int main()
{
	char *line;
	line = get_next_line(0);
	printf("%s", line);
	return (0);
}
