#include "soio.h"
#include "soio.c"
#include <stdio.h> //para usar printf
#include <unistd.h>
#include <stdlib.h>

int main()
{

  SOFILE *fp;

  char c;

  fp = sofopen("/home/dlavareda/Documents/UBI/2019-2020/SIstemas Operativos/P2/Parte 2/test.txt", "r");

  if (NULL != fp)
  {

    printf("Primeiro Caracter do ficheiro %c\n", sofgetc(fp));
    printf("Resto do ficheiro:--------------\n");
    while ((c = sofgetc(fp)) != EOF)
      write(1, &c, 1);
  }
  sofclose(fp);
  return 0;
}
