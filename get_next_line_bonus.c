/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:27:01 by paperez-          #+#    #+#             */
/*   Updated: 2024/06/10 13:04:32 by paperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static char	*ft_join(char *text, char *line)
{
	char	*tmp;

	tmp = ft_strjoin(text, line);
	free(line);
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
		buffer[byte_read] = 0;
		text = ft_strjoin(text, buffer);
		if (ft_strchr(buffer, '\n'))
			break;
	}
//	printf("este es el buffer en esta ejecucion: %s \n", text);
	return(text);
}

static char	*next_line(char *buffer)
{
	int	i;
	int	j;
	char	*line;

	i = ft_strlen(buffer) + 1;
	j = 0;
	while (buffer[j] != '\n' && j < i)
	{
		j++;
	}
	line = ft_calloc((j + 2), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
//	printf("esta es la linea en esta ejecucion %s \n", line);
	return (line);
}

static char	*rmfirstline(char *buffer, char *line)
{
	int	i;
	int	j;
	char	*newbuf;

	i = ft_strlen(line);
	j = ft_strlen(buffer);
	newbuf  = ft_calloc(j - i + 1, sizeof(char));
	if (!newbuf)
	{
		free(buffer);
		return (NULL);
	}
	j = 0;
	while(buffer[i + j + 1] && buffer[i + j + 1] != '\0')
	{
		newbuf[j] = buffer[i + j + 1];
		j++;
	}
	if (!newbuf)
		return (NULL);
	newbuf[j] = '\0';
//	printf("este es el newbuf de esta ejecucion %s", newbuf);
	return (newbuf);
}

char	*get_next_line(int fd)
{
	char	*line;
	static char	*buffer[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (0);
	line = next_line(buffer[fd]);
	buffer[fd] = rmfirstline(buffer[fd], line);
//	printf("este es el newbuf al final de esta ejecucion %s.\n", buffer);
	return (line);
}

int main ()
{
		char *line;
	int i = 0;
	int fd1 = open("prueba.txt", O_RDONLY);
	int fd2 = open("get_next_line.c", O_RDONLY);
	while (i < 16)
	{
		if ( i % 2 == 0)
			line = get_next_line(fd1);
		else
			line =  get_next_line(fd2);
		printf("esta es la %i linea del archivo %i: s\n", i/2, i % 2, line);
		i++;
	}
	return (0);
}
