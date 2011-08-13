#include "json-me.hpp" 
#include <iostream>
int main(int argc,char **argv) {
  jsonme::JsonMeLib jsonlib;
  jsonme::Node rootnode=jsonlib.parseFile("example.json");
  std::cerr << "Root node acquired, starting." << std::endl;
  bool disabled=rootnode["disabled"];
  std::cerr << "disabled:" << disabled << std::endl;
  size_t numberofclients=rootnode["devices"]["clients"].size();
  std::cerr << "Client count: " << numberofclients << std::endl;
  for (size_t index=0; index < numberofclients; index++) {
    jsonme::Node client=rootnode["devices"]["clients"][index];
    std::string device=client["device"];
    std::string group= client["groupname"];
    std::string ip=client["ip"];
    std::string net=client["net"];
    std::cerr << "client net: " << device << std::endl << "\tgroup\t:\t" <<  group << std::endl <<"\tip\t:\t" << ip << std::endl << "\tnet\t:\t" << net << std::endl;
  }
  jsonme::Node router=rootnode["devices"]["routers"];
  if (router.keys().size() < 4) {
    std::cerr << "No keys returned from routers." << std::endl;;
    return 1;
  }
  for (size_t keyindex=0;keyindex < router.keys().size() ; keyindex++) {
     std::cerr << "keys[" << keyindex << "] : " << std::endl;
     jsonme::AbstractKeys &keys=router.keys();
     std::string key=keys[keyindex];
     std::cerr << "    key=" << key << std::endl;
     std::string val=router[key];
     std::cerr << "    val=" << val << std::endl;
  }
  std::string device=router["device"];
  std::string group=router["groupname"];
  std::string ip= router["ip"];
  std::string net=router["net"];
  std::cerr << "router net: " << device << std::endl << "\tgroup\t:\t" << group << std::endl << "\tip\t:\t" << ip << std::endl << "\tnet\t:\t" << net << std::endl;
  size_t numberofgateways=rootnode["gateways"].size();
  for (size_t index=0; index < numberofgateways; index++) {
     jsonme::Node gateway=rootnode["gateways"][index];
     std::string name=gateway["name"];
     std::string gip=gateway["ip"];
     long long table = gateway["tableno"];
     jsonme::Node tn=gateway["tableno"];
     std::cerr << "gateway: " << name << std::endl << "\tip\t:\t" << gip <<  std::endl << "\ttable\t:\t" << table << std::endl;
     size_t groupcount=gateway["allowedgroups"].size();
     for (size_t index2=0; index2 < groupcount; index2++) {
       std::string group2=gateway["allowedgroups"][index2];
       std::cerr << "\tgroup\t:\t" << group2 << std::endl;
     }
  }
  return 0;
};
