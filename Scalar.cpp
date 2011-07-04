#include "json-me.hpp"

namespace jsonme {
      Scalar::Scalar(AbstractScalar *scalar):mScalar(scalar){}
      jsonme::scalartype Scalar::scalartype() {
        return mScalar->scalartype();
      }
      Scalar::operator long double() {
        return (*mScalar);
      }
      Scalar::operator long long() {
        return (*mScalar);
      }
      Scalar::operator std::string() {
        return (*mScalar);
      }
      Scalar::operator bool() {
        return (*mScalar);
      }
      bool Scalar::isNull() {
        return mScalar->isNull();
      }
}
