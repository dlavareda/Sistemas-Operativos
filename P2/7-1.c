#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
    /*(i) Escreva um programa (em C) para ler todo o conteúdo do ficheiro “test.bin” criado no exemplo 7.1 para
um vector usando as funções de open() e read() e depois imprimir no ecrã os valores dos inteiros lidos (512
513 ….521 etc.) usando printf()
Vai precisar da função open() com opção O_RDONLY e a função read()*/
/*int main()
{
    int fd, i, vec[10];
    fd = open("test.bin", O_RDONLY);
    read(fd, vec, sizeof(int) * 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", vec[i]);
    }
}*/

/*
Exercício 7.1:
(ii) Altere o programa para usar “shorts” em vez de “ints”
*/
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
/*
(iii) Experimente a utilização do programa strace (system call trace) na execução dos dois programas.
• O comando é : $strace ./ex71.exe
• Deverá tentar perceber porque o creat() devolve o descritor de ficheiro com valor de três (3)
• Experimenta a utilização do strace na execução do programa “mostrar” duma aula anterior.
*/