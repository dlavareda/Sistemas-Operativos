/*
 *  soio.c
 *
 *  Created by Paul Crocker on 3/11/07.
 *  Copyright 2007 UBI. All rights reserved.
 *
 */
#include "soio.h"

SOFILE *sofopen(const char *nome, const char *mode)
{
  SOFILE *novo = NULL;
  int fd;

  if (mode[0] == 'r')
    fd = open(nome, O_RDONLY, 0);
  else
    exit(1); //agora apenas para leitura !

  if (-1 == fd)
    return NULL; //caso erro

  novo = (SOFILE *)malloc(sizeof(SOFILE));
  novo->buf = (char *)malloc(MAXBUFFSIZE);
  novo->fd = fd;
  novo->index = 0;
  novo->size = 0;
  return novo;
}

//Funções não implementadas

int sofclose(SOFILE *fp)
{
  //sofclose() – fechar o ficheiro com close() e chamará a função free() duas vezes para libertar a memoria reservada
  close(fp->fd);
  free(fp->buf);
  free(fp);
  return 0;
}

int sofgetc(SOFILE *fp)
{ /*substituir este codigo */

  if (fp->index < 16 && fp->index > 0)
  {
    return fp->buf[fp->index++];
  }
  else
  {
    fp->index = 0;
    if (read(fp->fd, fp->buf, 16) == 0)
    {
      return EOF;
    }
    else
    {
      return fp->buf[fp->index++];
    }
  }
}

int sofflush(SOFILE *fp)
{
  while (fp->index < 16)
  {
    fp->buf[fp->index] = 0;
    fp->index++;
  }
  return 0;
}
