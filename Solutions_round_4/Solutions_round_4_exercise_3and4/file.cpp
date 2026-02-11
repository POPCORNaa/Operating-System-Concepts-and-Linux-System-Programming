#include <iostream>   // For C++ cin/cout
#include <fcntl.h>    // For creat()
#include <unistd.h>   // For write(), close(), and _exit()
#include <errno.h>    // For errno
#include <stdio.h>    // For perror()

using namespace std;

int main() {
    char userByte;
    const char* filename = "output.bin";

    // 1. Get input from user using C++
    cout << "Enter a single character to write to the file: ";
    cin >> userByte;

    // 2. Create the file (system call)
    // S_IRUSR | S_IWUSR sets read/write permissions for the owner (0600)
    int fd = creat(filename, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error creating file");
        _exit(1); // Immediate exit on failure
    }

    // 3. Write the byte (system call)
    // We pass the address of userByte and specify 1 byte length
    ssize_t bytesWritten = write(fd, &userByte, 1);
    if (bytesWritten == -1) {
        perror("Error writing to file");
        close(fd); // Try to clean up the file descriptor
        _exit(1);
    }

    // 4. Close the file (system call)
    if (close(fd) == -1) {
        perror("Error closing file");
        _exit(1);
    }

    cout << "Success! Byte '" << userByte << "' written to " << filename << endl;

    return 0;
}