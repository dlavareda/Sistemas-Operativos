#include "soio.h"
#include "soio.c"
#include <stdio.h> //para usar printf
#include <unistd.h>

int main()
{

  SOFILE *fp;
  int linhas = 0;
  char c;
  fprintf(stderr, "Main1\n");
  fp = sofopen("/home/dlavareda/Documents/UBI/2019-2020/SIstemas Operativos/P2/Parte 2/test.txt", "r");
  sofclose(fp);
  fp = sofopen("/home/dlavareda/Documents/UBI/2019-2020/SIstemas Operativos/P2/Parte 2/main1.c", "r");

  if (NULL != fp)
  {
    while ((c = sofgetc(fp)) != EOF)
    {
      if (linhas == 3)
      {
        sofflush(fp);
        continue;
      }
      if (c == '\n')
        linhas++;
      write(1, &c, 1);
    }
  }
  write(1, "\n", 1);
  sofclose(fp);
}
