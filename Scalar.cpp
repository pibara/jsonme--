#include "json-me.hpp"

namespace jsonme {
      class NullScalar: public AbstractScalar {
        public:
          jsonme::scalartype scalartype() const { return NULLVAL;}
          operator long double() const { return 0;}
          operator long long() const { return 0;}
          operator std::string() const { return "";}
          operator bool() const { return false;}
          bool isNull() const { return true;}
      };
      Scalar::Scalar():mScalar(new NullScalar()){}
      Scalar::Scalar(AbstractScalar *scalar):mScalar(scalar){}
      jsonme::scalartype Scalar::scalartype() const {
        return mScalar->scalartype();
      }
      Scalar::operator long double() const {
        return (*mScalar);
      }
      Scalar::operator long long() const {
        return (*mScalar);
      }
      Scalar::operator std::string() const {
        return (*mScalar);
      }
      Scalar::operator bool() const {
        return (*mScalar);
      }
      bool Scalar::isNull() const {
        return mScalar->isNull();
      }
}
