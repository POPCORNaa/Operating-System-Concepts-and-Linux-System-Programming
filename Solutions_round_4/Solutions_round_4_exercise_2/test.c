#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

int main() {
    int fd = open("this_file_does_not_exist.txt", O_RDONLY);

    if (fd == -1) {
        printf("Detected an error!\n");
        printf("Value of errno: %d\n", errno);
        printf("Error description: %s\n", strerror(errno));
        perror("Output from perror");
    }
    return 0;
}