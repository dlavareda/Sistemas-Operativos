#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUFFSIZE 128
void ioCopy(int IN, int OUT);
/*int main()
{
    ioCopy(STDIN_FILENO, STDOUT_FILENO); // 0 , 1
    return (0);
}*/
int main(int argc, char *argv[])
{
    int fdIn = open(argv[1], O_RDONLY);
    if (argc != 3)
    {
        printf("Nenhum argumento!\n");
        return 0;
    }
    if (fdIn > 0)
    {
        int fdOut = creat(argv[2], S_IRUSR | S_IWUSR);
        ioCopy(fdIn, fdOut);
    }
    else
    {
        perror("Erro de abertura!\n");
    }
    return 0;
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
