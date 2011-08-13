#include "../json-me.hpp" 
#include <iostream>
int main(int argc,char **argv) {
  jsonme::JsonMeLib jsonlib;
  try {
     jsonme::Node rootnode=jsonlib.parseFile("example.json");
     size_t numberofclients=rootnode["gateways"].size();
     if (numberofclients == 2) {
        return 0;
     }
     std::cerr << numberofclients << " found while 1 expected" << std::endl;
     return 1;
  } catch (jsonme::ParseError &e) {
     return 1;
  }
};
