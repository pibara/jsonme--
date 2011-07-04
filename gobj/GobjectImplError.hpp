#ifndef _JSONME_GOBJECTIMP_ERROR_HPP_
#define _JSONME_GOBJECTIMP_ERROR_HPP_
#include <glib-object.h>
namespace jsonme {
  namespace impl {
    class GobjectImplError {
        GError *mError;
      public:
        GobjectImplError();
        ~GobjectImplError();
        GError * error();
        GError ** errorp();
    };
  }
}
#endif
