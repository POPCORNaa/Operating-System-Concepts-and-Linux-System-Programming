#include <stdio.h>
#include <unistd.h>

int main(void){

    char buffer[1024];

    if (getcwd(buffer, sizeof(buffer)) == NULL){
        perror("failed");
        return 1;
    }

    printf("Current working directory: %s\n", buffer);
    return 0;
}