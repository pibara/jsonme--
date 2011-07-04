#ifndef _JSONME_GOBFECTIMPL_SCALAR_
#define _JSONME_GOBFECTIMPL_SCALAR_
#include "../json-me.hpp"
#include <glib-object.h>
#include <json-glib/json-glib.h>
namespace jsonme {
  namespace impl {
    class GobjectImplScalar: public AbstractScalar {
         JsonNode *mNode;
         GValue mValue;
       public:
         GobjectImplScalar(JsonNode *node);
         jsonme::scalartype scalartype();
         operator long double();
         operator long long();
         operator std::string();
         operator bool();
         bool isNull();   
    };
  }
}
#endif
