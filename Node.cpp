#include "json-me.hpp"
#include "NullKeys.hpp"
namespace jsonme {
      class NullNode: public AbstractNode {
          NullKeys mNullKeys;
        public:
          NullNode():mNullKeys(){}
          AbstractKeys & keys() { return mNullKeys;}
          jsonme::nodetype nodetype() const {return INVALID;}
          Node operator[](std::string const & name) const { return Node();}
          size_t size() const { return 0;}
          Node operator[](size_t index) const { return Node();}
          operator Scalar() const { return Scalar(); }
      };
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
