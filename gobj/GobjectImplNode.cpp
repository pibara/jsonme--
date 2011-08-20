//JsonMe++ C++ JSON parsing (wrapper) library.
//Copyright (C) Rob J Meijer 2011  <jsonme@polacanthus.net>
//
//This library is free software; you can redistribute it and/or
//modify it under the terms of the GNU Lesser General Public
//License as published by the Free Software Foundation; either
//version 2.1 of the License, or (at your option) any later version.
//
//This library is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//Lesser General Public License for more details.
//
//You should have received a copy of the GNU Lesser General Public
//License along with this library; if not, write to the Free Software
//Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
#include "GobjectImplFsTopNode.hpp"
#include "GobjectImplError.hpp"
#include "GobjectImplNode.hpp"
#include "GobjectImplScalar.hpp"
namespace jsonme {
  namespace impl {
     GobjectImplNode::GobjectImplNode(JsonNode * const node):mNode(node),mKeys(node) {
     } 
     //Maps Glib JSON lib enum to JsonMe++ lib enum.
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
        //Calling this operator on a non object returns a wrapped NullNode.
        if (!mNode) {
          return Node();
        }
        switch (json_node_get_node_type(mNode)) {
           case JSON_NODE_OBJECT: break;
           case JSON_NODE_ARRAY: return Node();
           case JSON_NODE_VALUE: return Node();
           case JSON_NODE_NULL: return Node();
        }
        JsonObject *asobject=json_node_get_object(mNode);
        if (asobject) {
          //Fetch the given property.
          JsonNode *member=json_object_get_member(asobject,name.c_str());
          if (member) {
            //Return the sub node.
            return Node(new GobjectImplNode(member));
          } else {
            //If there uis no such property return a wrapped NullNode
            return Node();
          }
        } else {
          return Node(); //This is probably dead code, just there in case.
        }
     }
     
     size_t GobjectImplNode::size() const {
        //Anything not an array has a zero size.
        if (!mNode) {
           return 0;
        }
        switch (json_node_get_node_type(mNode)) {
           case JSON_NODE_OBJECT: return 0;
           case JSON_NODE_ARRAY: break;
           case JSON_NODE_VALUE: return 0
           case JSON_NODE_NULL: return 0;
        }
        JsonArray *asarray=json_node_get_array(mNode);
        if (asarray) {
          return json_array_get_length(asarray); //Return the array length
        } else {
          return 0; //This is probably dead code, just there in case.
        }
     }

     Node GobjectImplNode::operator[](size_t index) const {
        //Calling this operator on a non array returns a wrapped NullNode.
        if (!mNode) {
           return Node();
        }
        switch (json_node_get_node_type(mNode)) {
           case JSON_NODE_OBJECT: return Node();
           case JSON_NODE_ARRAY: break;
           case JSON_NODE_VALUE: return Node();
           case JSON_NODE_NULL: return Node();
        }
        JsonArray *asarray=json_node_get_array(mNode);
        if (asarray) {
          //Fetch the indexed entity.
          JsonNode *member=json_array_get_element(asarray,index);
          if (member) {
             return Node(new GobjectImplNode(member)); //return the sub node.
          } else {
            return Node(); //Or a wraped NullNode if we can't find it.
          }
        } else {
          return Node(); //This is probably dead code, just there in case.
        }
     }
     GobjectImplNode::operator Scalar() const {
        //Only scalar type node's can be cast to a scalar. Other node's return a wrapped NullScalar.
        if (!mNode) {
           return Scalar();
        }
        if (this->nodetype() == jsonme::SCALAR) {
          return Scalar(new GobjectImplScalar(mNode));
        } else {
          return Scalar();
        } 
     }
  }
}
