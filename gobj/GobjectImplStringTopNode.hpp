#ifndef _JSONME_GOBJECTIMPL_STRINGTOPNODE_HPP
#define _JSONME_GOBJECTIMPL_STRINGTOPNODE_HPP
#include "../json-me.hpp"
#include "GobjectImplParser.hpp"
#include "GobjectImplNode.hpp"

namespace jsonme {
  namespace impl {
    class GobjectImplStringTopNode: public jsonme::AbstractNode {
        GobjectImplParser mParser;
        GobjectImplNode const * mRoot;
        NullKeys mNullKeys;
      public:
        GobjectImplStringTopNode(std::string const & jsonstring);
        ~GobjectImplStringTopNode() throw();
        AbstractKeys &keys() { return mNullKeys;}
        jsonme::nodetype nodetype() const ;
        Node operator[](std::string const & name) const ;
        size_t size() const;
        Node operator[](size_t index) const;
        operator Scalar() const;
    };
  }
}
#endif
