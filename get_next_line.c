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
		if (ft_strchr(buffer, '\n')
			break;
	}
	free(buffer);
	return(text);
}

static char	

static char	*next_line(char *buffer)
{
	int	i;
	int	j;
	char	*line;

	i = ft_strlen(buffer) + 1;
	j = i;
	while (buffer[j] != '\n' && j > 0))
	{
		j--;
	}
	line = ft_calloc((i - j + 1), sizeof(char));
	i = 0;
	while (buffer[j] != '\0')
	{
		line[i] = buffer[j];
		i++;
		j++;
	}
	free (buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = next_line(buffer);
	buffer = line;
	return (line);
}
