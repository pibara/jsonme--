#include "../json-me.hpp" 
#include <iostream>
int main(int argc,char **argv) {
  jsonme::JsonMeLib jsonlib;
  try {
     jsonme::Node rootnode=jsonlib.parseFile("example.json");
     jsonme::Node validnode=rootnode["devices"];
     if (validnode.nodetype() != jsonme::OBJECT) {
        return 2;
     } 
     bool asbool=validnode;
     if (asbool) {
        return 3;
     }
  } catch (jsonme::ParseError &e) {
     return 1;
  }
  return 0;
};
