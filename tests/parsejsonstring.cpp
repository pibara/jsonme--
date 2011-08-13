#include "../json-me.hpp" 
#include <iostream>
int main(int argc,char **argv) {
  jsonme::JsonMeLib jsonlib;
  try {
     jsonme::Node rootnode=jsonlib.parse("{\n\t\"foo\": 1,\n\t\"bar\": \"Blue\"\n}");
  } catch (jsonme::ParseError &e) {
     return 1;
  }
  return 0;
};
