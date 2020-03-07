/*
 *  soio.c
 *
 *  Created by Paul Crocker on 3/11/07.
 *  Copyright 2007 UBI. All rights reserved.
 *
 */
#include "soio.h"
#include <string.h> //para uso do memset

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

int sofclose(SOFILE *fp)
{
  close(fp->fd);
  free(fp->buf);
  free(fp);
  return 0;
}

int sofgetc(SOFILE *fp)
{
  if (fp->index > 0 && fp->index < 16)
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
  memset(fp->buf, 0, 16 * sizeof(char));
  fp->index = 0;
  fp->size = 0;
  return 0;
}
