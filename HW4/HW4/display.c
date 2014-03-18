#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
   int i;
    printf("*********DISPLAY*********\n");
    printf("Args: \n")
    for(i = 0; i < argc; i++)
    {
        printf("%s", argv[i]);
    }
}
