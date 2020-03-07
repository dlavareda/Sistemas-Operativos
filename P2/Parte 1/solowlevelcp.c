#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

/*
2. Faça as alterações necessárias ao seu programa para imprimir o tempo usado pelo CPU para efetuar a cópia do 
ficheiro. Deverá imprimir este valor no canal de stderr! Considere a sugestão seguinte:
clock_t inicio,fim; float tempoUsado;
inicio=clock();
.....FUNÇÂO DE COPIA....
fim=clock();
tempoUsado= (float)(fim-inicio)/ (float) CLOCKS_PER_SEC;
Exemplo $ ./solowlevelcp /etc/passwd passcopy 4
 Copia Feita com BlockSize 4 Tempo do CPU 0.150000
*/

void ioCopy(int IN, int OUT, int BUFFSIZE);

int main(int argc, char *argv[])
{
    int BUFFSIZE = atoi(argv[3]);
    int fdIn = open(argv[1], O_RDONLY);
    if (argc != 4)
    {
        printf("Erro no formato! Faltam argumentos\n");
        return 0;
    }
    else
    {
        if (fdIn > 0)
        {
            int fdOut = creat(argv[2], S_IRUSR | S_IWUSR);
            clock_t inicio, fim;
            float tempoUsado;
            inicio = clock();
            ioCopy(fdIn, fdOut, BUFFSIZE);
            fim = clock();
            tempoUsado = (float)(fim - inicio) / (float)CLOCKS_PER_SEC;
            fprintf( stderr, "Copia Feita com BlockSize %d Tempo do CPU %f\n", BUFFSIZE, tempoUsado);
        }
        return 0;
    }
}
void ioCopy(int IN, int OUT, int BUFFSIZE) //no error reporting
{
    int n;
    char *buf = malloc(BUFFSIZE);
    while ((n = read(IN, buf, BUFFSIZE)) > 0)
    {
        if (write(OUT, buf, n) != n)
            perror("Erro de escrita!\n");
    }
    if (n < 0)
        perror("Erro de leitura!\n");
}
