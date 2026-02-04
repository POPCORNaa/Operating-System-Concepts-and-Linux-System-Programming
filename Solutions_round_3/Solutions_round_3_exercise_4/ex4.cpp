#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char* argv[]) {
    //check if there is command
    if(argc< 2 ) {
        cout <<"Usage: " <<argv[0]<< "<command<[args...]"<<endl;
        return 1;
    }

    //make child process
    pid_t pid = fork ();
    if (pid<0){
        std::perror("fork faild");
        return 1;
    }
    else if (pid == 0){
        //command
        string full_path = "/bin/" + string(argv[1]);

        char** new_args = &argv[1];

        char* const env[] ={ NULL };
        execve(full_path.c_str(), new_args, env);

        //if failed
        execve(argv[1], new_args, env);
        std::perror("execve failed");
        return 1;
    }

    else{
        //parent logic
        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}


