#include "GobjectImplError.hpp"

namespace jsonme {
  namespace impl {
    GobjectImplError::GobjectImplError():mError(0){}
    GobjectImplError::~GobjectImplError(){
       if (mError) {
         g_error_free(mError);
         mError=0;
       }
    }
    GError * GobjectImplError::error() {
      return mError;
    }
    GError ** GobjectImplError::errorp(){
      return &mError;
    }
  }
}
