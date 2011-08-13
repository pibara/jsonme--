#include "../json-me.hpp" 
#include <iostream>
int main(int argc,char **argv) {
  jsonme::JsonMeLib jsonlib;
  try {
     jsonme::Node rootnode=jsonlib.parseFile("example.json");
     jsonme::Node bogusnode=rootnode["bogusnode"];
     if (bogusnode.nodetype() != jsonme::INVALID) {
        return 2;
     } 
     bool asbool=bogusnode;
     if (asbool) {
        return 3;
     }
     
  } catch (jsonme::ParseError &e) {
     return 1;
  }
  return 0;
};
