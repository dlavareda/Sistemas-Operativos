int main()
{
    int pid, x = 2;
    if ((pid = fork()) == 0)
    {
        fork();
        pid = fork();
        if (0 == pid)
            x--;
    }
    else
    {
        execl("/bin/date", "date", 0);
        x = x + 2;
    }
    printf("x=%d\n", x);
    return 0;
}