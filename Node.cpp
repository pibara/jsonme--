#include "json-me.hpp"

namespace jsonme {
      Node::Node():mNode(new NullNode()){}
      Node::Node(AbstractNode *node):mNode(node){}
      jsonme::nodetype Node::nodetype() const {
         return mNode->nodetype();
      }
      AbstractKeys & Node::keys() {
          return mNode->keys();
      }
      Node Node::operator[](std::string const & name) const {
         return (*mNode)[name];
      }
      Node Node::operator[](char const * const name) const {
         return (*mNode)[std::string(name)];
      }
      size_t Node::size() const {
        return mNode->size();
      }
      Node Node::operator[](size_t index) const {
        return (*mNode)[index];
      }
      Node::operator Scalar() const {
        return (*mNode);
      }
      jsonme::scalartype Node::scalartype() const{
        Scalar s(*mNode);
        return s.scalartype();
      }
      Node::operator long double() const {
        Scalar s(*mNode);
        return s;
      }
      Node::operator long long() const {
        Scalar s(*mNode);
        return s;
      }
      Node::operator std::string() const {
        Scalar s(*mNode);
        return s;
      }
      Node::operator bool() const {
        Scalar s(*mNode);
        return s;
      }
      bool Node::isNull() const {
        Scalar s(*mNode);
        return s.isNull();
      }
}
