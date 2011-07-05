#include "impl.hpp"
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "GobjectImplStringTopNode.hpp"
#include "GobjectImplFsTopNode.hpp"
namespace jsonme {
  namespace impl {
    GobjectLibImpl::GobjectLibImpl() {
      g_type_init ();
    }
    AbstractNode *GobjectLibImpl::parse(std::string const & jsonstring) const {
      return new GobjectImplStringTopNode(jsonstring);
    }
    AbstractNode *GobjectLibImpl::parseFile(std::string const & path) const { 
      return new GobjectImplFsTopNode(path); 
    }
  }
}
