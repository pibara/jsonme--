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
        GobjectImplFsTopNode(std::string const & jsonstring);
        ~GobjectImplFsTopNode();
        jsonme::nodetype nodetype() const;
        Node operator[](std::string const & name) const;
        size_t size() const;
        Node operator[](size_t index) const;
        operator Scalar() const;
    };
  }
}
#endif
