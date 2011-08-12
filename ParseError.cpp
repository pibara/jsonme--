#include "json-me.hpp"
namespace jsonme {
  ParseError::ParseError(std::string msg):mMessage(msg){}
  ParseError::~ParseError() throw() {}
  const char * ParseError::what() const throw() {
         return mMessage.c_str();
  }
}
