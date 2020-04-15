/*
   execute . cria um processo prog�nito e executa um programa
*/
#include "shell.h"

int ultimo(int numargs, char **args);

int containsPipe(int numArgs, char **args);

void execute(int numargs, char **args)
{
  int pid, status, pidFilho, fd[2];
  int code = ultimo(numargs, args);

  if ((pid = fork()) < 0)
  {                  /* cria um processo progenito */
    perror("forks"); /* NOTE: perror() produz uma pequema mensagem
				 * de erro para o stream */
    exit(1);         /* estandardizado de erros que descreve o * ultimo erro encontrado */
  }

  if (pid == 0)
  {
    int checker;
    int index = containsPipe(numargs, args);

    if (index > 0)
    {
      args[index] = NULL;
      pipe(fd);
      pidFilho = fork();
      if (pidFilho == 0)
      { //write
        args = args + index + 1;
        numargs = numargs - index - 1;
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
      }
      else
      { //read
        numargs = index;
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
      }
      checker = redirects(numargs, args);
      if (checker < 0)
      {
        exit(1);
      }
      execvp(*args, args);
      perror(*args);
      exit(1);
    }
    checker = redirects(numargs, args);
    if (checker < 0)
    {
      exit(1);
    }
    execvp(*args, args);
    perror(*args);
    exit(1);
  }

  if (FG == code)
  {
    while (wait(&status) != pid)
      ;
    return;
  }
}

int ultimo(int numargs, char **args)
{
  if (args[numargs - 1][0] == '&')
  {
    args[numargs - 1] = NULL;
    return BG;
  }
  if (args[numargs - 1][strlen(args[numargs - 1]) - 1] == ';')
  {
    args[numargs - 1][strlen(args[numargs - 1]) - 1] = 0;
  }
  return FG; /*return FG ou BG definidos no shell.h */
}

int containsPipe(int numArgs, char **args)
{
  int index;
  for (index = 0; index < numArgs; index++)
    if (args[index][0] == '|')
    {
      return index;
    }
  return -1;
}
