#include <sstream>

#include "minion.h"

minion::minion(){}

minion::minion(string env, string sname, string arg){
    environment = env;
    script_name = sname;
    arguments = arg;
}

minion::~minion(){}

void minion::execute(){}

void minion::set_env(string env){}

void minion::set_script(string sname){}

void minion::set_args(string args){}

std::string minion::to_string(){
    std::stringstream ss;
    ss 
        << environment 
        << " "
        << script_name
        << " "
        << arguments;
    return ss.str();
}
