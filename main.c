
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main ()
{
	int	fd = open("prueba.txt", O_RDONLY);
	char *str;

	str = get_next_line(fd);
	while(str)
	{
		str = get_next_line(fd);
		printf(str);
		free(str);
	}
	return (0);
}