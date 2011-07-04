#ifndef _JSONME_GOBJECTIMPL_STRINGTOPNODE_HPP
#define _JSONME_GOBJECTIMPL_STRINGTOPNODE_HPP
#include "../json-me.hpp"
#include "GobjectImplParser.hpp"
#include "GobjectImplNode.hpp"

namespace jsonme {
  namespace impl {
    class GobjectImplStringTopNode: public jsonme::AbstractNode {
        GobjectImplParser mParser;
        GobjectImplNode *mRoot;
      public:
        GobjectImplStringTopNode(std::string jsonstring);
        ~GobjectImplStringTopNode();
        jsonme::nodetype nodetype();
        Node operator[](std::string name);
        size_t size();
        Node operator[](size_t index);
        operator Scalar();
    };
  }
}
#endif
