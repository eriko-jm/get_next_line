
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens[2];
	size_t	i;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	lens[0] = ft_strlen(s1);
	lens[1] = ft_strlen(s2);
	str = malloc(sizeof(char) * ((lens[0] + lens[1]) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (i != lens[0])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i != lens[1])
	{
		str[lens[0]] = s2[i++];
		lens[0]++;
	}
	str[lens[0]] = '\0';
	return (str);
}
char	*ft_strchr(const char *s, int c)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = (char *)s;
	while (s2[i] != '\0')
	{
		if ((unsigned char)s2[i] == (unsigned char)c)
			return (&s2[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return (&s2[i]);
	return (NULL);
}
