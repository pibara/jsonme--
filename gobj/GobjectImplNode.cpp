#include "GobjectImplFsTopNode.hpp"
#include "GobjectImplError.hpp"
#include "GobjectImplNode.hpp"
#include "GobjectImplScalar.hpp"
namespace jsonme {
  namespace impl {
     GobjectImplNode::GobjectImplNode(JsonNode *node):mNode(node) {
     } 
     jsonme::nodetype GobjectImplNode::nodetype() {
        if (!mNode) {
           return  jsonme::INVALID;
        }
        switch (json_node_get_node_type(mNode)) {
           JSON_NODE_OBJECT: return jsonme::OBJECT;
           JSON_NODE_ARRAY: return jsonme::ARRAY;
           JSON_NODE_VALUE: return jsonme::SCALAR;
        }
        return  jsonme::INVALID;
     }
     Node GobjectImplNode::operator[](std::string name) {
        if (!mNode) {
          return Node(new GobjectImplNode(mNode));
        }
        JsonObject *asobject=json_node_get_object(mNode);
        return Node(new GobjectImplNode(json_object_get_member(asobject,name.c_str())));
     }
     size_t GobjectImplNode::size() {
        if (!mNode) {
           return 0;
        }
        JsonArray *asarray=json_node_get_array(mNode);
        return json_array_get_length(asarray);
     }
     Node GobjectImplNode::operator[](size_t index) {
        if (!mNode) {
           return Node(new GobjectImplNode(mNode));
        }
        JsonArray *asarray=json_node_get_array(mNode);
        return Node(new GobjectImplNode(json_array_get_element(asarray,index)));
     }
     GobjectImplNode::operator Scalar() {
        return Scalar(new GobjectImplScalar(mNode)); 
     }
  }
}
