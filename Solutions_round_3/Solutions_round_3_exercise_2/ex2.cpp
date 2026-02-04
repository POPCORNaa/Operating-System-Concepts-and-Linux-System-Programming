#include <iostream>
#include <unistd.h>

int main(){
    const char* path = "/bin/ls";

    char* const args[] = {(char*)"ls", NULL};

    char* const env[] = {NULL};

    execve(path, args, env);

    std::perror("execve failed");
    return 1;

}