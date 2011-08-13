#include "../json-me.hpp" 
#include <iostream>
int main(int argc,char **argv) {
  jsonme::JsonMeLib jsonlib;
  try {
     jsonme::Node rootnode=jsonlib.parseFile("Makefile");
  } catch (jsonme::ParseError &e) {
     return 0;
  }
  return 1;
};
