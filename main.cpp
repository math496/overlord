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
#include "overlord.h"

void help(std::string);

int main(int argc, char* argv[]){
    
    if ( argc == 1 ){
        help(argv[0]);
        return 0;
    }
    
    std::string filen = argv[1];
    overlord o(filen);
    
    o.read_json();
    o.run_subprocess();
    return 0;
}

void help(std::string filen){
    std::cout << "Usage: " 
              << filen 
              << " data_file.json" 
              << endl
              << "Outputs: results to output.txt"
              << endl;
}