#ifndef _JSONME_GOBJIMPL_PARSER_HPP
#define _JSONME_GOBJIMPL_PARSER_HPP
#include <glib-object.h>
#include <json-glib/json-glib.h>
namespace jsonme {
  namespace impl {
     class GobjectImplParser {
        JsonParser *mParser; 
       public:
        GobjectImplParser();
        ~GobjectImplParser();
        operator JsonParser *();
     };
  }
}
#endif
