#include <stdio.h>
void streamCopy (FILE * entrada, FILE * saida);
int main (int argc, char *argv[])
{

  if (1 == argc)
    {
      streamCopy (stdin, stdout);
    }
  else
    {
      FILE *f = NULL;;
      if ((f = fopen (argv[1], "r")) == NULL)
	{
	  fprintf (stderr, " %s:Fatal Error ", argv[1]);
	  perror(NULL);
	}
      else
	{
	  streamCopy (f, stdout);
	}
    }

}

void streamCopy (FILE * entrada, FILE * saida)
{
  int ch;
  while ((ch = fgetc (entrada)) != EOF)
    {
      fputc (ch, saida);
    }
}
