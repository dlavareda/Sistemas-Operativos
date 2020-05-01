#include "shell.h"

int copy(int in, int out, int bsize){

	int     n;
	int BUFFSIZE = bsize;
	char * buf=malloc(BUFFSIZE);

	while ((n = read(in, buf, BUFFSIZE)) > 0){
		if (write(out, buf, n) != n)
			perror("Erro de escrita!\n");
	}
	if (n < 0){
		perror("Erro de leitura!\n");
		return(0);
	}
	return 0;
}

void * copywrapper(void *args) {
	copiar_t * ptr = (copiar_t *)args;
	int in = open (ptr->fonte,O_RDONLY);
	int out= creat (ptr->destino,FILE_MODE);
	
	copy( in,out,ptr->buffsize); 
	free(ptr);
	return NULL;
}