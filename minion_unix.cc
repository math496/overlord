#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <boost/format.hpp>
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

void minion::execute(std::string filename){
    std::string execution = format_test_string(filename);
    
    pid_t pid = fork();
    switch (pid){
        case -1: 
            std::cerr << execution << " failed to execute." << endl;
            exit(1);
        case 0:
            execl( execution.c_str(), NULL);
            exit(1);
        default:
            int status;
            while ( !WIFEXITED(status) ) waitpid(pid, &status, 0);
            
            return; 
    }
}

std::string minion::format_test_string(std::string filename){
    boost::format formater( to_string() );
    formater % filename;
    return formater.str();
}