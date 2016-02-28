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

void overlord::read_tests(){
    boost::property_tree::ptree pt;
    boost::property_tree::read_json(filename, pt);
    
    BOOST_FOREACH( boost::property_tree::ptree::value_type &v, pt.get_child("runtime") ){
        string env, name, args;
        BOOST_FOREACH(boost::property_tree::ptree::value_type& itemPair, v.second){
            if ( itemPair.first == "env" ){
                env = itemPair.second.get_value<std::string>(); 
            }
            else if ( itemPair.first == "script_name" ){
                name = itemPair.second.get_value<std::string>();
            }
            else if ( itemPair.first == "arguments" ) {
                args = itemPair.second.get_value<std::string>();
            }
        }
        minion m(env, name, args);
        subroutines.push_back(m);
    }
}

void overlord::read_test_files(){
    boost::property_tree::ptree pt;
    boost::property_tree::read_json(filename, pt);
    
    BOOST_FOREACH( boost::property_tree::ptree::value_type &v, pt.get_child("testFiles") ){
        test_files.push_back( v.second.get_value<std::string>() );
    }
}

void overlord::read_json(){
    read_tests();
    read_test_files();
}

void overlord::run_subprocess(){
    for ( std::vector<minion>::iterator it = subroutines.begin() ; it != subroutines.end() ; ++it ){
        it->execute();
    }
}
