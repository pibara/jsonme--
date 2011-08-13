#ifndef _JSONME_GOBFECTIMPL_SCALAR_
#define _JSONME_GOBFECTIMPL_SCALAR_
#include "../json-me.hpp"
#include <glib-object.h>
#include <json-glib/json-glib.h>
namespace jsonme {
  namespace impl {
    class GobjectImplScalar: public AbstractScalar {
         JsonNode * const mNode;
         GValue mValue;
         GobjectImplScalar(const GobjectImplScalar &);
         GobjectImplScalar & operator=(const GobjectImplScalar&);
       public:
         GobjectImplScalar(JsonNode * const node);
         ~GobjectImplScalar() throw();
         jsonme::scalartype scalartype() const;
         operator long double() const;
         operator long long() const;
         operator std::string() const;
         operator bool() const;
         bool isNull() const;   
    };
  }
}
#endif
