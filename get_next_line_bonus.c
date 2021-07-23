#include "get_next_line_bonus.h"

int	ft_len(char **string)
{
	int	len;

	len = 0;
	while ((*string)[len] != '\n' && (*string)[len] != '\0')
		len++;
	return (len);
}

void	ft_free(char **str)
{
	free(*str);
	*str = NULL;
}

int	ft_left(char **string, char **line)
{
	int		len;
	char	*remainder;

	len = 0;
	if (!(*string))
	{
		*line = ft_strdup("");
		return (0);
	}
	len = ft_len(string);
	if (ft_strchr(*string, '\n'))
	{
		*line = ft_substr(*string, 0, len);
		remainder = ft_substr(*string, len + 1, ft_strlen(*string));
		free(*string);
		*string = ft_strdup(remainder);
		ft_free(&remainder);
	}
	else
	{
		*line = ft_strdup(*string);
		ft_free(&(*string));
		return (0);
	}
	return (1);
}

int	add_words(int bytes, char *buf, int fd, char **line)
{
	static char	*string[1024];
	char		*temp;

	while (bytes > 0)
	{
		buf[bytes] = '\0';
		if (!string[fd])
			string[fd] = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(string[fd], buf);
			free(string[fd]);
			string[fd] = ft_strdup(temp);
			ft_free(&temp);
		}
		if (ft_strchr(string[fd], '\n'))
			break ;
		bytes = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (bytes < 0)
		return (-1);
	else if (!string[fd] || (string[fd] && bytes >= 0))
		return (ft_left(&string[fd], line));
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	int			bytes;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buf = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	bytes = read(fd, buf, BUFFER_SIZE);
	return (add_words(bytes, buf, fd, line));
}
