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
//Curently the glib implementation is the only one implemented, so USE_GOBJECT_JSON_LIB better be defined.
#ifdef USE_GOBJECT_JSON_LIB
#define _JSON_LIB_DEFINED_
#include "gobj/impl.hpp"
namespace jsonme {
  typedef jsonme::impl::GobjectLibImpl LibImpl;
}
#endif
//Maybe we can create an second build for jsonme using an application based on boost::property_tree
//For now we don't have such an implementation yet.
#ifdef USE_BOOST_JSON_LIB
#error Boost implementation not yet implemented.
#endif
#ifndef _JSON_LIB_DEFINED_
#error low level lib undefined
#endif
namespace jsonme {
  //Constructor creates a wrapper for a dynamicaly allocated library implementation object.
  JsonMeLib::JsonMeLib():mLibImpl(new LibImpl()) {}
  //Destructor
  JsonMeLib::~JsonMeLib() throw() {}
  //The pare method gets forwarded to the implementation.
  Node JsonMeLib::parse(std::string const & jsonstring) const {
    return mLibImpl->parse(jsonstring);
  }
  //The parseFile gets forwarded to the implementation.
  Node JsonMeLib::parseFile(std::string const & path) const {
    return mLibImpl->parseFile( path);
  }
  Node JsonMeLib::object() const {
    return mLibImpl->object();
  }
  Node JsonMeLib::array() const {
    return mLibImpl->array();
  }

}

