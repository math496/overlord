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

int main(void){
    
    std::string filen = "data.json";
    overlord o(filen);
    
    o.read_json();
    o.run_subprocess();
    return 0;
}