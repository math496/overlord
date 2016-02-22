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
#include <fstream>
#include <string>

#include "overlord.h"

overlord::overlord(std::string filen){
    filename = filen;
}

overlord::~overlord(){
    subroutines.clear();
}

void overlord::read_json(){
    boost::property_tree::ptree pt;
    boost::property_tree::read_json(filename, pt);
    
    BOOST_FOREACH( boost::property_tree::ptree::value_type &v, pt.get_child("runtime") ){
        string env, name, args;
        int i = 0;
        BOOST_FOREACH(boost::property_tree::ptree::value_type& itemPair, v.second){
            if ( i == 0 ){
                env = itemPair.second.get_value<std::string>(); 
            }
            else if ( i == 1 ){
                name = itemPair.second.get_value<std::string>();
            }
            else {
                args = itemPair.second.get_value<std::string>();
            }
            std::cout
                << i
                << " : " 
                << itemPair.second.get_value<std::string>() 
                << " " 
                << endl;
            i++;
            
        }
        minion m(env, name, args);
        subroutines.push_back(m);
        cout << endl;
        
    }
}

void overlord::run_subprocess(){
    for ( std::vector<minion>::iterator it = subroutines.begin() ; it != subroutines.end() ; ++it ){
        cout << it->to_string() << endl;
    }
}
