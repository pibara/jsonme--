#ifndef _JSONME_GOBJECTIMP_ERROR_HPP_
#define _JSONME_GOBJECTIMP_ERROR_HPP_
#include <glib-object.h>
namespace jsonme {
  namespace impl {
    class GobjectImplError {
        GError *mError;
        GobjectImplError(const GobjectImplError&);
        GobjectImplError &operator=(const GobjectImplError&);
      public:
        GobjectImplError();
        ~GobjectImplError();
        GError * error();
        GError ** errorp();
    };
  }
}
#endif
