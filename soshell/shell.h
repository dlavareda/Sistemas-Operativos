#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>
#include <sys/wait.h>
#include <math.h>

typedef struct
{
    char msg[100];
    int tempo;
} aviso_t;
typedef struct
{
    char fonte[100];
    char destino[100];
    int buffsize;
} copiar_t;
int parse(char *buf, char **args);

void execute(int, char **args);

int builtin(char **args, int);

void socp(char *, char *);

void ioCopy(int, int);

int ultimo(int, char **);

void calc(char *, char *, char *);

void bits(char *, char *, char *);

int isjpg(int);

int redirects(int, char *[]);

int containsPipe(int, char **);

void aviso(char *, int);

void *avisowrapper(void *);
void *copywrapper(void *);
int copy(int, int, int);
/* constantes que podem tornar uteis*/

#define BG 0
#define FG 1
#define FILE_MODE ( S_IRUSR | S_IWUSR)