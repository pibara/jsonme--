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
#ifndef _JSONME_GOBJECTIMPL_FSTOPNODE_HPP
#define _JSONME_GOBJECTIMPL_FSTOPNODE_HPP
#include "../json-me.hpp"
#include "GobjectImplParser.hpp"
#include "GobjectImplNode.hpp" 
namespace jsonme {
  namespace impl {
    //Glib json based implementation of an AbstractNode representing the top node of the JSON tree constructed from a JSON file.
    class GobjectImplFsTopNode: public jsonme::AbstractNode {
        GobjectImplParser mParser; //resource managed parser object.
        GobjectImplNode *mRoot; //The node we will forward most our method calls to.
        GobjectImplFsTopNode(const GobjectImplFsTopNode&); //prohibit copy
        GobjectImplFsTopNode & operator=(const GobjectImplFsTopNode&); //prohibit assignment.
      public:
        GobjectImplFsTopNode(std::string const & jsonstring);
        ~GobjectImplFsTopNode() throw();
        AbstractKeys &keys();
        jsonme::nodetype nodetype() const;
        Node operator[](std::string const & name) const;
        size_t size() const;
        Node operator[](size_t index) const;
        operator Scalar() const;
    };
  }
}
#endif
