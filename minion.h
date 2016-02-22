#ifndef MINION_H
#define MINION_H

#include <string>
#include <cstdlib>

using namespace std;

class minion {
    public:
    
        minion();
        
        minion(string, string, string);
        
        ~minion();
        
        void execute();
        
        /**
         * Set runtime environment
        **/
        void set_env(string);
        
        /**
         * Location of script for env to run 
        **/
        void set_script(string);
        
        /**
         * Script command line arguments.
        **/
        void set_args(string);
        
        /**
         * Return the execution as a string
        **/
        std::string to_string();
        
    private:
        string environment,
               script_name,
               arguments;
};

#endif