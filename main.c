#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    char    *line;
    int fd = open("test.txt", O_RDONLY);

    line = get_next_line(fd);
    while (line)
    {
        printf("line: '%s'", line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
}