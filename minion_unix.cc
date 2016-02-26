#include <iostream>
#include "minion.h"

void minion::execute(){
    pid_t pid = fork();
    switch (pid){
        case -1: 
            std::cerr << to_string() << " failed to execute." << endl;
            exit(1);
        case 0:
            execl( to_string().c_str(), NULL);
            exit(1);
        default:
            int status;
            while ( !WIFEXITED(status) ) waitpid(pid, &status, 0);
            
            return; 
    }
}
