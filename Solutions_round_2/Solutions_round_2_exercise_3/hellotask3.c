#include <stdio.h>

int main(int argc, char *argv[])
{
    int repeat_count = 3;
    char *name = "Guest";

    if (argc<2)
    {
        printf("Usage: %s <name>\n", argv[0]);
    }
    else
    {
        printf("Hello %s!\n", argv[1]);
    }

    printf("ready to repeat ...\n");
    for (int i = 0; i < repeat_count; i++)
    {
        printf("message %d : have a great day, %s!\n", i + 1, name);
    }

    return 0;


}