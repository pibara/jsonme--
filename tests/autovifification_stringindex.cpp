#include "../json-me.hpp" 
#include <iostream>
int main(int argc,char **argv) {
  jsonme::JsonMeLib jsonlib;
  try {
     jsonme::Node object=jsonlib.object();
     object["bar"]["a"]="aa";
     std::string jsonstring = object;
     if (jsonstring == std::string("")) {
        return 2;
     }
     std::cout << jsonstring;
  } catch (jsonme::ParseError &e) {
     return 1;
  }
  return 0;
};
