#include "get_next_line.h"

int	ft_bytes(char *string)
{
	int	len;

	len = 0;
	if (!string)
		return (0);
	while (string[len])
	{
		if (string[len] == '\n')
			return (1);
		len++;
	}
	return (0);
}

char	*ft_cpy(char *string)
{
	int		len;
	char	*temp;

	len = 0;
	if (!string)
		return (0);
	while (string[len] && string[len] != '\n')
		len++;
	temp = (char *) malloc(sizeof(char) * len + 1);
	if (!temp)
		return (0);
	len = 0;
	while (string[len] && string[len] != '\n')
	{
		temp[len] = string[len];
		len++;
	}
	temp[len] = '\0';
	return (temp);
}

char	*ft_left(char *string)
{
	int		str_len;
	int		temp_len;
	char	*temp;

	str_len = 0;
	temp_len = 0;
	if (!string)
		return (0);
	while (string[str_len] && string[str_len] != '\n')
		str_len++;
	if (!string[str_len])
	{
		ft_free(&string);
		return (0);
	}
	temp = (char *) malloc(sizeof(char) * ((ft_strlen(string) - str_len) + 1));
	if (!temp)
		return (0);
	str_len++;
	while (string[str_len])
		temp[temp_len++] = string[str_len++];
	temp[temp_len] = '\0';
	ft_free(&string);
	return (temp);
}

int	ft_add(int *bytes, int fd, char **buf, char **string)
{
	char	*temp;

	*bytes = read(fd, *buf, BUFFER_SIZE);
	if ((*bytes) == -1)
	{
		ft_free(buf);
		return (-1);
	}
	(*buf)[*bytes] = '\0';
	temp = ft_strdup(*string);
	ft_free(string);
	*string = ft_strjoin(temp, *buf);
	ft_free(&temp);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	int			bytes;
	static char	*string;

	bytes = 1;
	if (fd < 0 || fd >= 65536 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buf = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	while (!ft_bytes(string) && bytes != 0)
	{
		if (ft_add(&bytes, fd, &buf, &string) == -1)
			return (-1);
	}
	ft_free(&buf);
	*line = ft_cpy(string);
	string = ft_left(string);
	if (bytes == 0)
		return (0);
	return (1);
}
