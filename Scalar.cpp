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

#include "json-me.hpp"

namespace jsonme {
      //This implements the NullObject design pattern for the AbstractScalar interface.
      class NullScalar: public AbstractScalar {
        public:
          jsonme::scalartype scalartype() const { return NULLVAL;}
          operator long double() const { return 0;}
          operator long long() const { return 0;}
          operator std::string() const { return "";}
          operator bool() const { return false;} 
          bool isNull() const { return true;}
          NullScalar & operator=(long double) { return *this;}
          NullScalar & operator=(long long) { return *this;}
          NullScalar & operator=(std::string) { return *this;}
          NullScalar & operator=(bool) { return *this;}
      };
      //The default constructor wraps a NullScalar.
      Scalar::Scalar():mScalar(new NullScalar()){}
      //Alternative constructor wraps a dynamically allocated  implementation of the AbstractScalar interface.
      Scalar::Scalar(AbstractScalar *scalar):mScalar(scalar){}
      //Simple method forwarding.
      jsonme::scalartype Scalar::scalartype() const {
        return mScalar->scalartype();
      }
      //Simple forwarding of the real cast.
      Scalar::operator long double() const {
        return (*mScalar);
      }
      //Simple forwarding of the real cast.
      Scalar::operator long long() const {
        return (*mScalar);
      }
      //Simple forwarding of the real cast.
      Scalar::operator std::string() const {
        return (*mScalar);
      }
      //Simple forwarding of the real cast.
      Scalar::operator bool() const {
        return (*mScalar);
      }
      //Simple forwarding of the real cast.
      bool Scalar::isNull() const {
        return mScalar->isNull();
      }
      Scalar & Scalar::operator=(long double i) {
        (*mScalar) = i;
        return *this;
      }
      Scalar & Scalar::operator=(long long i) {
        (*mScalar) = i;
        return *this;
      }
      Scalar & Scalar::operator=(std::string i) {
        (*mScalar) = i;
        return *this;
      }
      Scalar & Scalar::operator=(bool i) {
        (*mScalar) = i;
        return *this;
      }
}
