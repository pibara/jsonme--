#ifndef _JSONME_GOBJ_LIB_IMPL_
#define _JSONME_GOBJ_LIB_IMPL_
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include "../json-me.hpp"
namespace jsonme {
  namespace impl {
    class GobjectLibImpl: public AbstractLibImpl {
      public:
        GobjectLibImpl();
        Node parse(std::string const & jsonstring) const;
        Node parseFile(std::string const  & path) const ;
    };
  }
}
#endif
