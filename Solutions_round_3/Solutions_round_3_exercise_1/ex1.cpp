#include <iostream>

int main(int argc, char* argv[]){
    int argumentCount = argc - 1;

    std::cout << "Number of command line arguments: " << argumentCount << std::endl;
    std::cout << "And they are: " << std::endl;

    for (int i = 1; i < argc; i++)
    {
       std::cout << "     " << argv[i]<< std::endl;
    }

    return 0;


}