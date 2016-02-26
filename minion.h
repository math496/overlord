#ifndef MINION_H
#define MINION_H

#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

class minion {
    public:
    
        minion(){
            environment = "";
            script_name = "";
            arguments = "";
        }
        
        minion(std::string env, std::string sname, std::string arg){
            environment = env;
            script_name = sname;
            arguments = arg;
        }
        
        ~minion(){}
        
        void execute();
        
        /**
         * Set runtime environment
        **/
        void set_env(std::string env){
            environment = env;
        }
        
        /**
         * Location of script for env to run 
        **/
        void set_script(std::string sname){
            script_name = sname;
        }
        
        /**
         * Script command line arguments.
        **/
        void set_args(std::string args){
            arguments = args;
        }
        
        /**
         * Return the execution as a string
        **/
        std::string to_string(){
            std::stringstream ss;
            ss 
                << environment 
                << " "
                << script_name
                << " "
                << arguments;
            return ss.str();
        }
        
    private:
        std::string environment,
               script_name,
               arguments;
};

#endif