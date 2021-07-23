#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
void	ft_free(char **str);

#endif
