#include "../json-me.hpp" 
#include <iostream>
int main(int argc,char **argv) {
  jsonme::JsonMeLib jsonlib;
  try {
     jsonme::Node rootnode=jsonlib.parseFile("example.json");
  } catch (jsonme::ParseError &e) {
     return 1;
  }
  return 0;
};
