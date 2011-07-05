#include "GobjectImplFsTopNode.hpp"
#include "GobjectImplError.hpp"
#include "GobjectImplNode.hpp"
#include "GobjectImplScalar.hpp"
namespace jsonme {
  namespace impl {
     GobjectImplNode::GobjectImplNode(JsonNode * const node):mNode(node) {
     } 
     jsonme::nodetype GobjectImplNode::nodetype() const {
        if (!mNode) {
           return  jsonme::INVALID;
        }
        switch (json_node_get_node_type(mNode)) {
           case JSON_NODE_OBJECT: return jsonme::OBJECT;
           case JSON_NODE_ARRAY: return jsonme::ARRAY;
           case JSON_NODE_VALUE: return jsonme::SCALAR;
           case JSON_NODE_NULL: return jsonme::INVALID;
        }
        return  jsonme::INVALID;
     }
     Node GobjectImplNode::operator[](std::string const & name) const {
        if (!mNode) {
          return Node();
        }
        JsonObject *asobject=json_node_get_object(mNode);
        if (asobject) {
          JsonNode *member=json_object_get_member(asobject,name.c_str());
          if (member) {
            return Node(new GobjectImplNode(member));
          } else {
            return Node();
          }
        } else {
          return Node();
        }
     }
     size_t GobjectImplNode::size() const {
        if (!mNode) {
           return 0;
        }
        JsonArray *asarray=json_node_get_array(mNode);
        if (asarray) {
          return json_array_get_length(asarray);
        } else {
          return 0;
        }
     }
     Node GobjectImplNode::operator[](size_t index) const {
        if (!mNode) {
           return Node(new GobjectImplNode(mNode));
        }
        JsonArray *asarray=json_node_get_array(mNode);
        if (asarray) {
          JsonNode *member=json_array_get_element(asarray,index);
          if (member) {
             return Node(new GobjectImplNode(member));
          } else {
            return Node();
          }
        } else {
          return Node();
        }
     }
     GobjectImplNode::operator Scalar() const {
        if (this->nodetype() == jsonme::SCALAR) {
          return Scalar(new GobjectImplScalar(mNode));
        } else {
          return Scalar();
        } 
     }
  }
}
