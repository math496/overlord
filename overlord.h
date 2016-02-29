#ifndef OVERLORD_H
#define OVERLORD_H

#ifdef _MSC_VER
#include <boost/config/compiler/visualc.hpp>
#endif
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <cassert>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>

#include "minion.h"

class overlord {
    
    public:
        // Take in JSON filename
        overlord(std::string);
        
        // Destroy the overlord!
        ~overlord();
        
        // Read the file from the constructor
        void read_json();
    
        // Make some minions, and execute them.
        void run_subprocess();
    private:
        std::string filename;
        std::vector<minion> subroutines;
        std::vector<std::string> test_files;
        
        // Read the files from json that are to be tested.
        void read_test_files();
        
        // Read the tests that are to be ran on the files.
        void read_tests();
        
        // Determines if "%s" exists inside string
        std::size_t find_boost_format_string(std::string);
        
};

#endif