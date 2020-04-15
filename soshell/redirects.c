#include "shell.h"
#define FILE_MODE (S_IRUSR | S_IWUSR)
//redirects are handled in reverse order
// 2> >> > <

int redirects(int numargs, char *args[])
{
    //redirect stdout >
    if (numargs < 3)
    {
        return numargs;
    }
    if (strcmp(args[numargs - 2], ">") == 0)
    {
        int fd = creat(args[numargs - 1], FILE_MODE);
        if (fd < 0)
        {
            perror(NULL);
            return -1; /*indicar um erro*/
        }
        dup2(fd, STDOUT_FILENO);
        close(fd);
        args[numargs - 2] = NULL;
        numargs = numargs - 2;
    }
    if (numargs < 3)
    {
        return numargs;
    }
    if (strcmp(args[numargs - 2], ">>") == 0 && numargs > 3)
    {
        int fd = open(args[numargs - 1], O_WRONLY | O_APPEND);
        if (fd < 0)
        {
            perror(NULL);
            return -1;
        }
        dup2(fd, STDOUT_FILENO);
        close(fd);
        args[numargs - 2] = NULL;
        numargs = numargs - 2;
    }
    if (strcmp(args[numargs - 2], "<") == 0 && numargs > 3)
    {
        int fd = open(args[numargs - 1], O_RDONLY);
        if (fd < 0)
        {
            perror(NULL);
            return -1;
        }
        dup2(fd, STDIN_FILENO);
        close(fd);
        args[numargs - 2] = NULL;
        numargs = numargs - 2;
    }
    if (strcmp(args[numargs - 2], "2>") == 0 && numargs > 3)
    {
        int fd = creat(args[numargs - 1], FILE_MODE);
        if (fd < 0)
        {
            perror(NULL);
            return -1;
        }
        dup2(fd, STDERR_FILENO);
        close(fd);
        args[numargs - 2] = NULL;
        numargs = numargs - 2;
    }

    //tratar do >> open : O_WRONLY | O_APPEND
    //tratar do < open : O_RDONLY
    return numargs;
}