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

int parse(char *buf, char **args);

void execute(int, char **args);

int builtin(char **args, int);

void socp(char *, char *);

void ioCopy(int, int);

int ultimo(int *, char **args);

void calc(char *, char *, char *);
/* constantes que podem tornar uteis*/

#define BG 0
#define FG 1
