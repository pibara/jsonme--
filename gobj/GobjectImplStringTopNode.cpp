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
#include "GobjectImplStringTopNode.hpp"
#include "GobjectImplError.hpp"
#include "GobjectImplNode.hpp"
#include "GobjectImplScalar.hpp"
namespace jsonme {
  namespace impl {
     //Constructor.
     GobjectImplStringTopNode::GobjectImplStringTopNode(std::string const & jsonstring):mParser(),mRoot(0) {
       GobjectImplError lerror; //Resource managed place for storing our error state.
       json_parser_load_from_data (mParser,jsonstring.c_str(),jsonstring.size(),lerror.errorp());
       if (lerror.error()) {
          throw jsonme::ParseError(lerror.error()->message);
       }
       mRoot=new GobjectImplNode(json_parser_get_root(mParser)); //Wrap the root node.
     } 
     //Destructor destroys the wrapped node.
     GobjectImplStringTopNode::~GobjectImplStringTopNode() throw() {
       delete mRoot;
     }
     //Simple method forwarding.
     jsonme::nodetype GobjectImplStringTopNode::nodetype() const {
        return mRoot->nodetype();
     }
     //Simple method forwarding.
     Node GobjectImplStringTopNode::operator[](std::string const & name) const {
        return (*mRoot)[name];
     }
     //Simple method forwarding.
     size_t GobjectImplStringTopNode::size() const {
        return mRoot->size();
     }
     //Simple method forwarding.
     Node GobjectImplStringTopNode::operator[](size_t index) const {
        return (*mRoot)[index];
     }
     //Simple method forwarding.
     GobjectImplStringTopNode::operator Scalar() const {
        return (*mRoot);
     }
  }
}
