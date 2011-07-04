#include "json-me.hpp"

namespace jsonme {
      Node::Node(AbstractNode *node):mNode(node){}
      jsonme::nodetype Node::nodetype() {
         return mNode->nodetype();
      }
      Node Node::operator[](std::string name){
         return (*mNode)[name];
      }
      Node Node::operator[](const char *name) {
         return (*mNode)[std::string(name)];
      }
      size_t Node::size(){
        return mNode->size();
      }
      Node Node::operator[](size_t index){
        return (*mNode)[index];
      }
      Node::operator Scalar() {
        return (*mNode);
      }
      jsonme::scalartype Node::scalartype(){
        Scalar s(*mNode);
        return s.scalartype();
      }
      Node::operator long double() {
        Scalar s(*mNode);
        return s;
      }
      Node::operator long long() {
        Scalar s(*mNode);
        return s;
      }
      Node::operator std::string() {
        Scalar s(*mNode);
        return s;
      }
      Node::operator bool() {
        Scalar s(*mNode);
        return s;
      }
      bool Node::isNull() {
        Scalar s(*mNode);
        return s.isNull();
      }
}
