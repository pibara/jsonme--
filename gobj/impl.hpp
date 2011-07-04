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
        AbstractNode *parse(std::string jsonstring);
        AbstractNode *parseFile(std::string path);
    };
  }
}
#endif
