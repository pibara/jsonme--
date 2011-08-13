#include "../json-me.hpp" 
#include <iostream>
int main(int argc,char **argv) {
  jsonme::JsonMeLib jsonlib;
  try {
     jsonme::Node rootnode=jsonlib.parseFile("example.json");
     //An object is always true
     jsonme::Node validnode=rootnode["devices"];
     if (validnode.nodetype() != jsonme::OBJECT) {
        std::cerr << "Expected devices node to be an object." << std::endl;
        return 2;
     } 
     bool asbool=validnode;
     if (!asbool) {
        std::cerr << "Expected object node to be an TRUE" << std::endl;
        return 3;
     }
     //An empty array is false
     jsonme::Node emptyarray=rootnode["devices"]["clients"];
     if (emptyarray.nodetype() != jsonme::ARRAY) {
        std::cerr << "Expected devices::clients node to be an (empty) array." << std::endl;
        if (emptyarray.nodetype() != jsonme::INVALID) {
           std::cerr << "Its invalid." << std::endl;
        } else if  (emptyarray.nodetype() != jsonme::SCALAR) {
           std::cerr << "Its a scalar." << std::endl;
        } else if (emptyarray.nodetype() != jsonme::OBJECT) {
          std::cerr << "Its an object" << std::endl;
        }
        return 4;
     }
     asbool = emptyarray;
     if (asbool) {
        std::cerr << "Expected empty array node to be an FALSE" << std::endl;
        return 5;
     }
     //An non empty array is true.
     jsonme::Node fullarray=rootnode["gateways"];
     if (fullarray.nodetype() != jsonme::ARRAY) {
        std::cerr << "Expected gateways node to be an array." << std::endl;
        return 6;
     }
     asbool = fullarray;
     if (!asbool) {
        std::cerr << "Expected non empty array node to be a TRUE" << std::endl;
        return 7;
     }
     //A string scalar is true
     jsonme::Node scal=rootnode["devices"]["routers"]["device"];
     if (!asbool) {
        std::cerr << "Expected string scalar node to be a TRUE" << std::endl;
        return 7;
     }
  } catch (jsonme::ParseError &e) {
     return 1;
  }
  return 0;
};
