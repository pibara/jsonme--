#include "../json-me.hpp" 
#include <iostream>
int main(int argc,char **argv) {
  jsonme::JsonMeLib jsonlib;
  try {
     jsonme::Node rootnode=jsonlib.parseFile("example.json");
     jsonme::Node router=rootnode["devices"]["routers"];
     if (router.keys().size() != 4) {
        std::cerr << "Bad number of keys (" << router.keys().size() << ") returned from routers." << std::endl;;
        return 2;
     }
     return 0;
  } catch (jsonme::ParseError &e) {
     return 1;
  }
};
