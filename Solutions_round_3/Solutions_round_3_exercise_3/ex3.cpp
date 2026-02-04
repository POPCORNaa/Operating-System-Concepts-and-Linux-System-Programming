#include <iostream>
#include <unistd.h> //fork
#include <sys/wait.h> //waitpid
#include <sys/types.h> //pid_t

using std::cout;
using std::endl;

int main(){
    //make child process

    pid_t pid = fork();

    if (pid < 0)
    {
        //fork failed
        std::perror("fork failed");
        return 1;
    }
    else if (pid == 0){
        //child process
        const char* path = "/bin/ls";
        char* const args[] ={ (char*)"ls", NULL};
        char* const env[] = {NULL};

        //child process become ls
        execve(path, args, env);

        std::perror("execve failed");
        return 1;
    }
    else{
        //parent process

        int status;
        //waiting for child process to stop
        waitpid(pid, &status, 0);
    }
    return 0;
}