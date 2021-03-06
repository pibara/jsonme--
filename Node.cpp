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
#include "json-me.hpp"
#include "NullKeys.hpp"
namespace jsonme {
      //Implementing the NullObject pattern for the AbstractNode interface.
      class NullNode: public AbstractNode {
          NullKeys mNullKeys; //If we need to return an AbstractKeys object reference, a NullKeys object is needed. 
        public:
          NullNode():mNullKeys(){}
          AbstractKeys & keys() { return mNullKeys;}
          jsonme::nodetype nodetype() const {return INVALID;}
          Node operator[](std::string const & name) const { return Node();}
          size_t size() const { return 0;}
          Node operator[](size_t index) const { return Node();}
          operator Scalar() const { return Scalar(); }
      };
      //The default constructor creates a node wrapping a NullNode.
      Node::Node():mNode(new NullNode()){}
      //A second constructor wraps some kind of  AbstractNode subclass.
      Node::Node(AbstractNode *node):mNode(node){}
      //Simply forward method to the implementation.
      jsonme::nodetype Node::nodetype() const {
         return mNode->nodetype();
      }
      //Simply forward method to the implementation.
      AbstractKeys & Node::keys() {
          return mNode->keys();
      }
      //Simply forward method to the implementation.
      Node Node::operator[](std::string const & name) const {
         return (*mNode)[name];
      }
      //Forwarder with cstring to std::string conversion.
      Node Node::operator[](char const * const name) const {
         return (*mNode)[std::string(name)];
      }
      //Simply forward method to the implementation.
      size_t Node::size() const {
        return mNode->size();
      }
      //Simply forward method to the implementation.
      Node Node::operator[](size_t index) const {
        return (*mNode)[index];
      }
      //Simpe trick to forward this method to the implementation.
      Node::operator Scalar() const {
        return (*mNode);
      }
      //Two step forwarder: 1) cast node to scalar. 2) forward method.
      jsonme::scalartype Node::scalartype() const{
        Scalar s(*mNode);
        return s.scalartype();
      }
      //Two step forwarder: 1) cast node to scalar. 2) forward method.
      Node::operator long double() const {
        Scalar s(*mNode);
        return s;
      }
      //Two step forwarder: 1) cast node to scalar. 2) forward method.
      Node::operator long long() const {
        Scalar s(*mNode);
        return s;
      }
      //Two step forwarder: 1) cast node to scalar. 2) forward method.
      Node::operator std::string() const {
        Scalar s(*mNode);
        return s;
      }
      //Node type dependant casting to boolean.
      Node::operator bool() const {
        switch (mNode->nodetype()) {
           case INVALID: //Invalid nodes are always false.
              return false; 
           case OBJECT: //Objects are always true.
              return true;
           case ARRAY: //Empty arrays are false, non empty arrays are true.
              return (mNode->size() != 0);
           case SCALAR: //Scalars take care of their own casting to boolean.
              Scalar s(*mNode);
              return s;   
        }
        //This code should not get reached, just in case lets return false.
        return false;
      }
      //Two step forwarder: 1) cast node to scalar. 2) forward method.
      bool Node::isNull() const {
        Scalar s(*mNode);
        return s.isNull();
      }
}
