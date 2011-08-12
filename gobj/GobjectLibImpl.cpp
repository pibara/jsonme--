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
    Node GobjectLibImpl::parse(std::string const & jsonstring) const {
      return Node(new GobjectImplStringTopNode(jsonstring));
    }
    Node GobjectLibImpl::parseFile(std::string const & path) const { 
      return Node(new GobjectImplFsTopNode(path)); 
    }
  }
}
