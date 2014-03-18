#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if(argc < 1)
    {
        printf("Error, generate received no arguments.\n");
        exit(-1);
    }

    int nData = atoi(argv[1]);
    int i;
    fprintf(stderr,"*********GENERATE*********\n");
    fprintf(stderr,"Args: \n")
    for(i = 0; i < argc; i++)
    {
        fprintf(stderr, "%s ", argv[i]);
    }


    int input;

    fprintf(stderr, "Enter an integer: ");
    scanf("%d", input);

    fprintf(stdout,"%d\n", input);

    fflush(stdout);
    close(stdout);

    exit(nData + input);
}
