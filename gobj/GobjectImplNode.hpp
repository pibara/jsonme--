#ifndef _JSONME_GOBFECTIMPL_NODE_
#define _JSONME_GOBFECTIMPL_NODE_
#include "../json-me.hpp"
#include <glib-object.h>
#include <json-glib/json-glib.h>
namespace jsonme {
  namespace impl {
    class GobjectImplNode: public AbstractNode {
        JsonNode *mNode;
      public:
        GobjectImplNode(JsonNode *node);
        jsonme::nodetype nodetype();
        Node operator[](std::string name);
        size_t size();
        Node operator[](size_t index);
        operator Scalar();
    };
  }
}
#endif
