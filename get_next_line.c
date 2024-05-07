
static char	*read_file(int fd)
{
	static char	*buffer;
	char		*line;

	
}

static char	*next_line(int fd, char *buffer)
{
	
}

char	*get_next_line(int fd)
{
	int	bytes_read;
	char	*line;
	static char	*buffer;

	line = get_line(buffer, fd);
	buffer = ft_calloc(ft_strlen(line) + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	bytes_read = read(fd, buffer, ft_strlen(line));
	if (bytes_read <= 0)
		return (NULL);
	

}
