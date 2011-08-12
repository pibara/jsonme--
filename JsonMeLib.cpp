#include "json-me.hpp"
#ifdef USE_GOBJECT_JSON_LIB
#define _JSON_LIB_DEFINED_
#include "gobj/impl.hpp"
namespace jsonme {
  typedef jsonme::impl::GobjectLibImpl LibImpl;
}
#endif
#ifdef USE_BOOST_JSON_LIB
#error Boost implementation not yet implemented.
#endif
#ifndef _JSON_LIB_DEFINED_
#error low level lib undefined
#endif
namespace jsonme {
  JsonMeLib::JsonMeLib():mLibImpl(new LibImpl()) {}
  JsonMeLib::~JsonMeLib() throw() {}
  Node JsonMeLib::parse(std::string const & jsonstring) const {
    return mLibImpl->parse(jsonstring);
  }
  Node JsonMeLib::parseFile(std::string const & path) const {
    return mLibImpl->parseFile( path);
  }
}

