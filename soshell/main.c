#include "shell.h"
/*#include "parse.c"
#include "execute.c"
#include "socp.c"
#include "calc.c"
#include "redirects.c"
#include "files.c"*/
char prompt[100];

int main()
{
  int len;
  char linha[1024]; /* um comando */
  char *args[64];   /* com um maximo de 64 argumentos */

  strcpy(prompt, "SOSHELL: Introduza um comando : prompt>");
  while (1)
  {
    printf("%s", prompt);
    if (fgets(linha, 1023, stdin) == NULL)
    {
      printf("\n");
      exit(0);
    }
    len = strlen(linha);
    if (1 == len)
      continue; /* linha é apenas \n */
    if (linha[len - 1] == '\n')
      linha[len - 1] = '\0';
    int numarg = parse(linha, args); /* particiona a string em argumentos */

    if (!builtin(args, numarg))
      execute(numarg, args); /* executa o comando */
  }
  return 0;
}

int builtin(char **args, int numarg)
{
  if (strcmp(args[0], "sair") == 0)
  {
    exit(0);
    return 1;
  }
  if (strncmp(args[0], "42", 2) == 0)
  {
    printf("42 is the answer to life the universe and everything\n");
    return 1; /* funcionalidade embutida */
  }
  if (0 == strcmp(args[0], "obterinfo"))
  {
    printf("SoShell 2020 versão 1.0\n");
    printf("™ Diogo Lavareda\n");
    return 1; //comando embutido
  }
  if (strlen(args[0]) > 4 && 0 == strncmp(args[0], "PS1=", 4))
  {
    strcpy(prompt, args[0] + 4);
    return 1; //comando embutido
  }
  if (0 == strcmp(args[0], "quemsoueu"))
  {
    system("id");
    return 1; //comando embutido
  }
  if (0 == strcmp(args[0], "cd"))
  {
    int err;

    if (NULL == args[1] || strcmp(args[1], "~") == 0)
    {
      err = chdir(getenv("HOME"));
    }
    else
    {
      err = chdir(args[1]);
    }
    if (err < 0)
    {
      perror(args[1]);
    }
    return 1; //comando embutido
  }
  if (0 == strcmp(args[0], "socp"))
  {
    socp(args[1], args[2]);
    return 1; //comando embutido
  }
  if (0 == strcmp(args[0], "calc") && numarg == 4)
  {
    calc(args[1], args[2], args[3]);
    return 1; //comando embutido
  }
  if ((0 == strcmp(args[0], "bits") && numarg == 4) || (0 == strcmp(args[0], "bits") && (0 == strcmp(args[2], "~") && numarg == 3)))
  {
    if (args[3] == NULL)
    {
      args[3] = "";
    }
    bits(args[1], args[2], args[3]);
    return 1; //commando embutido
  }
  if (0 == strcmp(args[0], "isjpg"))
  {
    if (open(args[1], O_RDONLY) > 0)
    {
      int result = isjpg(open(args[1], O_RDONLY));
      if (result == 1)
      {
        printf("O ficheiro é jpg\n");
      }
      else
      {
        printf("O ficheiro não é jpg\n");
      }
    }
    else
    {
      printf("Ficheiro não encontrado\n");
    }
    return 1; //comando embutido
  }
  if (strcmp(args[0], "avisoTeste") == 0)
  {
    aviso(args[1], atoi(args[2]));
    return 1;
  }
  if (strcmp(args[0], "aviso") == 0)
  {
    pthread_t th;
    aviso_t *ptr = (aviso_t *)malloc(sizeof(aviso_t));
    strcpy(ptr->msg, args[1]);
    ptr->tempo = atoi(args[2]);
    pthread_create(&th, NULL, avisowrapper, (void *)ptr);
    return 1;
  }
  if (strcmp(args[0], "socpth") == 0)
  {
    pthread_t th;
    copiar_t *ptr = (copiar_t *)malloc(sizeof(copiar_t));
    strcpy(ptr->fonte, args[1]);
    strcpy(ptr->destino, args[2]);
    ptr->buffsize = 256;
    pthread_create(&th, NULL, copywrapper, (void *)ptr);
    return 1;
  }
  /* IMPORTANTE : 
   Devolver 0 para indicar que não existe comando embutido e que
   será executado usando exec() na função execute.c
  */
  return 0;
}
