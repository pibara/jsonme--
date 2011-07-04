#ifndef _JSONME_GOBJECTIMPL_FSTOPNODE_HPP
#define _JSONME_GOBJECTIMPL_FSTOPNODE_HPP
#include "../json-me.hpp"
#include "GobjectImplParser.hpp"
#include "GobjectImplNode.hpp" 
namespace jsonme {
  namespace impl {
    class GobjectImplFsTopNode: public jsonme::AbstractNode {
        GobjectImplParser mParser;
        GobjectImplNode *mRoot;
      public:
        GobjectImplFsTopNode(std::string jsonstring);
        ~GobjectImplFsTopNode();
        jsonme::nodetype nodetype();
        Node operator[](std::string name);
        size_t size();
        Node operator[](size_t index);
        operator Scalar();
    };
  }
}
#endif
