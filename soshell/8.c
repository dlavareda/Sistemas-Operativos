#include "shell.h"

long int findSize(char file_name[])
{
    FILE *f = fopen(file_name, "r");

    if (f == NULL)
    {
        printf("Ficheiro %s nao encontrado!\n", file_name);
        return -1;
    }
    fseek(f, 0L, SEEK_END);
    long int tamanho = ftell(f);
    fclose(f);
    return tamanho;
}
int main()
{

    //verificar qual é o ficherio maior
    if (strcmp(args[0], "maior") == 0)
    {

        long int file1 = 0, file2 = 0;

        file1 = findSize(args[1]);
        file2 = findSize(args[2]);

        if (file1 != -1 && file2 != -1)
        {
            if (file1 == file2)
            {
                printf("Os ficheiros são iguais e têm de tamanho %ld KB!\n", file1);
                return 1;
            }
            else if (file1 > file2)
            {
                printf("O ficheiro: %s é maior e tem %ld KB!\n", args[1], file1);
                return 1;
            }
            else
            {
                printf("O ficheiro: %s é maior e tem %ld KB!\n", args[2], file2);
                return 1;
            }
        }
        return 1;
    }

    //atribuição da permissão de execução
    if (strcmp(args[0], "setx") == 0)
    {

        chmod(args[1], S_IRWXU);
        printf("Feita atribuição da permissão de execução para o dono do ficheiro %s!\n", args[1]);
        return 1;
    }

    //atribuição da permissão de execução
    if (strcmp(args[0], "setx") == 0)
    {

        if (chmod(args[1], S_IRWXU | S_IRGRP | S_IWGRP | S_IROTH) == 0)
        {
            printf("Feita atribuição da permissão de execução para o dono do ficheiro %s!\n", args[1]);
            return 1;
        }
        else
        {
            printf("Erro na alteração de atribuição do ficheiro %s!\n", args[1]);
        }
        return 1;
    }

    //retirar permissão de leitura para o grupo
    if (strcmp(args[0], "removerl") == 0)
    {

        if (chmod(args[1], S_IRUSR | S_IWUSR | S_IWGRP) == 0)
        {
            printf("Feita a retirada da permissão de leitura para o grupo do ficheiro %s!\n", args[1]);
            return 1;
        }
        else
        {
            printf("Erro na alteração de atribuição do ficheiro %s!\n", args[1]);
        }
        return 1;
    }
}