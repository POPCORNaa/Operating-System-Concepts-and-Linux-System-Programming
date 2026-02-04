#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>

using namespace std;

// display prompt on the screen
void type_prompt() {
    cout << "Enter a command: ";
    cout.flush();
}

// read input from terminal
bool read_command(string &command, vector<char*> &parameters) {
    string line;
    if (!getline(cin, line) || line.empty()) {
        return false; // stop if empty
    }

    stringstream ss(line);
    string part;
    parameters.clear();

    if (ss >> part) {
        command = part;
        // first parameter is the command itself
        parameters.push_back(strdup(part.c_str()));

        // get other parameters
        while (ss >> part) {
            parameters.push_back(strdup(part.c_str()));
        }
    }

    // must end with NULL
    parameters.push_back(NULL);
    return true;
}

int main() {
    while (true) { // repeat forever
        string command;
        vector<char*> parameters;

        type_prompt();

        if (!read_command(command, parameters)) {
            cout << "Program run stops running" << endl;
            break;
        }

        // fork off child process
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork failed");
        }
        else if (pid == 0) {
            // Child code
            char* const env[] = { NULL };

            // try to execute
            execve(command.c_str(), parameters.data(), env);

            // try with /bin/ if simple command
            string full_path = "/bin/" + command;
            execve(full_path.c_str(), parameters.data(), env);

            // if still fails
            perror("execve failed");
            exit(1);
        }
        else {
            // Parent code
            int status;
            waitpid(pid, &status, 0); // wait for child to exit
        }

        // clean memory
        for (char* p : parameters) {
            if (p) free(p);
        }
    }

    return 0;
}