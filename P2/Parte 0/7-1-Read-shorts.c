#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd, i, vec[10];
    fd = open("test.bin", O_RDONLY);
    read(fd, vec, sizeof(short) * 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", vec[i]);
    }
}