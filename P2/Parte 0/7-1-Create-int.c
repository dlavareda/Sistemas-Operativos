#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
/*
Exemplo 7.1:
O programa em baixo ilustra a criação dum ficheiro e a escrita neste ficheiro dum vector de dez inteiros.
Ler, Escrever, Compilar e Executar o programa.
*/
int main()
{
 int fd, i, vec[10];
 for (i=0;i <10; i++)
 vec[i]=i+512;
 fd = creat("/home/dlavareda/Documents/UBI/2019-2020/SIstemas Operativos/P2/test.bin", S_IRUSR| S_IWUSR ) ;
 write(fd, vec , sizeof(int)*10);
 return (0);
}

