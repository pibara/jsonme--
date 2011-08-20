//JsonMe++ C++ JSON parsing (wrapper) library.
//Copyright (C) Rob J Meijer 2011  <jsonme@polacanthus.net>
//
//This library is free software; you can redistribute it and/or
//modify it under the terms of the GNU Lesser General Public
//License as published by the Free Software Foundation; either
//version 2.1 of the License, or (at your option) any later version.
//
//This library is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//Lesser General Public License for more details.
//
//You should have received a copy of the GNU Lesser General Public
//License along with this library; if not, write to the Free Software
//Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
#include "GobjectImplError.hpp"

namespace jsonme {
  namespace impl {
    GobjectImplError::GobjectImplError():mError(0){}
    GobjectImplError::~GobjectImplError(){
       //If needed invoke g_error_free to avoid resource leaks.
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
