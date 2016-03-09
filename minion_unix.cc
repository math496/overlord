#include <iostream>
#include <sstream>
#include <unistd.h>
#include <boost/format.hpp>
#include "minion.h"

void minion::execute(){
    std::stringstream ss; 
    ss << to_string() << " >> output.txt";
    system(ss.str().c_str()); 
    return;
}

void minion::execute(std::string filename){
    std::stringstream ss;
    std::string execution = format_test_string(filename);
    ss << execution << " >> output.txt";
    system(ss.str().c_str()); 
    return;
}

std::string minion::format_test_string(std::string filename){
    boost::format formater( to_string() );
    formater % filename;
    return formater.str();
}