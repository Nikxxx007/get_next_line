#include "get_next_line_bonus.h"

char	*ft_strdup(const char *str)
{
	char	*memory;
	int		i;

	i = 0;
	if (!str)
		return (0);
	memory = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!memory)
		return (NULL);
	while (str[i])
	{
		memory[i] = str[i];
		i++;
	}
	memory[i] = '\0';
	return (memory);
}

char	*ft_strchr(const char *string, int symbol)
{
	int	i;

	i = 0;
	if (!string || !symbol)
		return (NULL);
	while (string[i])
	{
		if (string[i] == (char)symbol)
			return ((char *)(string + i));
		i++;
	}
	if (string[i] == symbol)
		return ((char *)(string + i));
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!result)
		return (NULL);
	while (s1[i])
		result[j++] = s1[i++];
	i = 0;
	while (s2[i])
		result[j++] = s2[i++];
	result[j] = '\0';
	return (result);
}

size_t	ft_strlen(const char *str)
{
	int	temp;

	if (str == NULL)
		return (0);
	temp = 0;
	while (str[temp])
		temp++;
	return (temp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*memory;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	memory = (char *)malloc(sizeof(char) * (len + 1));
	if (!memory)
		return (NULL);
	while (i < len && s[start] && start < ft_strlen(s))
		memory[i++] = s[start++];
	memory[i] = '\0';
	return (memory);
}
