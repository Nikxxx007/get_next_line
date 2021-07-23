#include "get_next_line.h"

void	ft_free(char **str)
{
	free(*str);
	*str = NULL;
}

char	*ft_strdup(const char *str)
{
	char	*memory;
	size_t	i;

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

void	*ft_memmove(void *destptr, const void *srcptr, size_t num)
{
	unsigned char	*arr;
	unsigned char	*arr_s;
	size_t			i;

	arr = (unsigned char *)destptr;
	arr_s = (unsigned char *)srcptr;
	i = -1;
	if (!num || destptr == srcptr)
		return (destptr);
	if (srcptr < destptr)
	{
		while ((int)(--num) >= 0)
			*(arr + num) = *(arr_s + num);
	}
	else
	{
		while (++i < num)
			*(arr + i) = *(arr_s + i);
	}
	return (destptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (0);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	result = malloc(sizeof(char) * (s1_len + s2_len) + 1);
	if (!result)
		return (0);
	ft_memmove(result, s1, s1_len);
	ft_memmove(result + s1_len, s2, s2_len);
	result [s1_len + s2_len] = '\0';
	return (result);
}
