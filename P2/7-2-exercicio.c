#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUFFSIZE 128
void ioCopy(int IN, int OUT);

int main(int argc, char *argv[])
{
    int fdIn = open(argv[1], O_RDONLY);
    if (argc != 3)
    {
        printf("Erro no formato! Faltam argumentos\n");
        return 0;
    }
    else
    {
        if (fdIn > 0)
        {
            int fdOut = creat(argv[2], S_IRUSR | S_IWUSR);
            ioCopy(fdIn, fdOut);
        }
        return 0;
    }
}
void ioCopy(int IN, int OUT) //no error reporting
{
    int n;
    char buf[BUFFSIZE];
    while ((n = read(IN, buf, BUFFSIZE)) > 0)
    {
        if (write(OUT, buf, n) != n)
            perror("Erro de escrita!\n");
    }
    if (n < 0)
        perror("Erro de leitura!\n");
}
