#include "shell.h"

void socp(char *fonte, char *destino)
{
    int fdIn = open(fonte, O_RDONLY);
    if (fdIn > 0)
    {
        int fdOut = creat(destino, S_IRUSR | S_IWUSR);
        ioCopy(fdIn, fdOut);
    }
}
void ioCopy(int IN, int OUT)
{
    int n;
    char *buf = malloc(16);
    while ((n = read(IN, buf, 16)) > 0)
    {
        if (write(OUT, buf, n) != n)
            perror("Erro de escrita!\n");
    }
    if (n < 0)
        perror("Erro de leitura!\n");
}