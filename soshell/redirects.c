#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

#define FILE_MODE (S_IRUSR | S_IWUSR)

//redirects are handled in reverse order
// 2>  >> > <
int redirects(int numargs, char *args[])
{
	//redirect stdout >
	if (numargs < 3)
		return numargs;
	if (strcmp(args[numargs - 2], "<") == 0)
	{
		int fd = open(args[numargs - 1], O_RDONLY);
		if (fd < 0)
		{
			perror("Erro: ");
			return -1; /*indicar um erro*/
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
		args[numargs - 2] = NULL;
		numargs = numargs - 2;
	}
	else if (strcmp(args[numargs - 2], ">") == 0)
	{
		int fd = creat(args[numargs - 1], FILE_MODE);
		if (fd < 0)
		{
			perror("Erro: ");
			return -1; /*indicar um erro*/
		}
		dup2(fd, STDOUT_FILENO);
		close(fd);
		args[numargs - 2] = NULL;
		numargs = numargs - 2;
	}
	else if (strcmp(args[numargs - 2], ">>") == 0)
	{
		int fd = open(args[numargs - 1], O_WRONLY | O_APPEND);
		if (fd < 0)
		{
			perror("Erro: ");
			return -1; /*indicar um erro*/
		}
		dup2(fd, STDOUT_FILENO);
		close(fd);
		args[numargs - 2] = NULL;
		numargs = numargs - 2;
	}
	else if (strcmp(args[numargs - 2], "2>") == 0)
	{
		int fd = open(args[numargs - 3], O_RDONLY);
		if (fd < 0)
		{
			fd = creat(args[numargs - 1], FILE_MODE);
			dup2(fd, STDERR_FILENO);
			close(fd);
			args[numargs - 2] = NULL;
			numargs = numargs - 2; /*indicar um erro*/
		}
		else
		{
			fd = creat(args[numargs - 1], FILE_MODE);
			dup2(fd, STDERR_FILENO);
			close(fd);
			args[numargs - 2] = NULL;
			numargs = numargs - 2;
		}
	}

	redirects(numargs, args);

	return numargs;
}