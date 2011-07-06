#ifndef _JSONME_GOBFECTIMPL_NODE_
#define _JSONME_GOBFECTIMPL_NODE_
#include "../json-me.hpp"
#include <glib-object.h>
#include <json-glib/json-glib.h>
namespace jsonme {
  namespace impl {
    class GobjectImplNode: public AbstractNode {
        JsonNode * const mNode;
        NullKeys mNullKeys;
      public:
        GobjectImplNode(JsonNode * const node);
        AbstractKeys &keys() { return mNullKeys;}
        jsonme::nodetype nodetype() const ;
        Node operator[](std::string const & name) const ;
        size_t size() const;
        Node operator[](size_t index) const ;
        operator Scalar() const;
    };
  }
}
#endif
