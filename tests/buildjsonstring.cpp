#include "../json-me.hpp" 
#include <iostream>
int main(int argc,char **argv) {
  jsonme::JsonMeLib jsonlib;
  try {
     jsonme::Node object=jsonlib.object();
     long long x=-12345;
     object["foo"]=x;
     object["bar"][(size_t) 0]["a"]="aa";
     object["bar"][(size_t) 0]["b"]="bb";
     object["bar"][(size_t) 1]["a"]="aaaa";
     object["bar"][(size_t) 1]["b"]="bbbb";
     std::string jsonstring = object;
     std::cout << jsonstring;
  } catch (jsonme::ParseError &e) {
     return 1;
  }
  return 0;
};
