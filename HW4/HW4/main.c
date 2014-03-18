#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int i;
    printf("*********CALCULATE*********\n");
    printf("Args: \n");
    for(i = 0; i < argc; i++)
    {
        printf("%s", argv[i]);
    }


    pid_t cpid1 = -1;
    pid_t cpid2 = -1;

    int pipeds1[2];
    int pipeds2[2];

    if(pipe(pipeds1) < 0 || pipe(pipeds2) < 0)
    {
        printf("Error creating pipes.\n");
        exit(-1);
    }



    cpid1 = fork();

    if(cpid1 < 0)
    {
        printf("Error forking first child.\n");
        exit(-2);
    }
    else if(cpid1 == 0)
    {
        close(pipeds1[0]);

        dup2(pipeds1[1], 1);

        close(pipeds1[1]);

        close(pipeds2[0]);
        close(pipeds2[1]);

        execl("generate", argv[1], NULL);
        //error message
        exit(0);

    }

    cpid2 = fork();

    if(cpid2 < 0)
    {
        printf("Error forking second child.\n");
        exit(-2);
    }
    else if(cpid2 == 0)
    {
        close(pipeds2[1]);

        dup2(pipeds2[0], 0);

        close(pipeds2[0]);

        close(pipeds1[0]);
        close(pipeds1[1]);

        execl("display", argv[2], argv[3], NULL);
        exit(0);
    }

    close(pipeds1[1]);
    close(pipeds2[0]);



    return 0;
}
