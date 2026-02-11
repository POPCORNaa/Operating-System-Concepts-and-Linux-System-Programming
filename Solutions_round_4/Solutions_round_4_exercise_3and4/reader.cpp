#include <iostream>   // For C++ cout
#include <fcntl.h>    // For open() and O_RDONLY
#include <unistd.h>   // For read(), close(), and _exit()
#include <stdio.h>    // For perror()

using namespace std;

int main() {
    const char* filename = "output.bin";

    // 1. Create a C-style char buffer.
    // Since we only expect 1 byte, a size of 1 is sufficient.
    char buffer[1];

    // 2. Open the file (System Call)
    // According to 'man 2 open', O_RDONLY is used for read-only access.
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file for reading");
        _exit(1);
    }

    // 3. Read the byte (System Call)
    // read(file_descriptor, buffer_address, number_of_bytes)
    ssize_t bytesRead = read(fd, buffer, 1);

    if (bytesRead == -1) {
        perror("Error reading from file");
        close(fd);
        _exit(1);
    } else if (bytesRead == 0) {
        cout << "The file is empty." << endl;
        close(fd);
        _exit(1);
    }

    // 4. Close the file (System Call)
    if (close(fd) == -1) {
        perror("Error closing file");
        _exit(1);
    }

    // 5. Print the result using C++
    cout << "Successfully read from file. The character is: " << buffer[0] << endl;

    return 0;
}