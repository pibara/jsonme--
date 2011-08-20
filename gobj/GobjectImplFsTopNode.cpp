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
     //Constructor.
     GobjectImplFsTopNode::GobjectImplFsTopNode(std::string const & path):mParser(),mRoot(0) {
       GobjectImplError lerror; //Use a RAII like object for holding our error state.
       json_parser_load_from_file (mParser,path.c_str(), lerror.errorp());
       if (lerror.error()) {
          throw jsonme::ParseError(lerror.error()->message);
       }
       mRoot=new GobjectImplNode(json_parser_get_root(mParser)); // Wrap the root node from the file.
     } 
     //Destructor, destroy the node that we wrap.
     GobjectImplFsTopNode::~GobjectImplFsTopNode() throw() {
       delete mRoot; 
     }
     //Simple method forwarding.
     jsonme::nodetype GobjectImplFsTopNode::nodetype() const {
        return mRoot->nodetype();
     }
     //Simple method forwarding.
     Node GobjectImplFsTopNode::operator[](std::string const & name) const {
        return (*mRoot)[name];
     }
     //Simple method forwarding.
     size_t GobjectImplFsTopNode::size() const {
        return mRoot->size();
     }
     //Simple method forwarding.
     Node GobjectImplFsTopNode::operator[](size_t index) const {
        return (*mRoot)[index];
     }
     //Simple method forwarding. 
     GobjectImplFsTopNode::operator Scalar() const {
        return (*mRoot);
     }
     //Simple method forwarding.
     AbstractKeys &GobjectImplFsTopNode::keys() { 
        return mRoot->keys();
     }
  }
}
