#include "GobjectImplParser.hpp"
namespace jsonme {
  namespace impl {
    GobjectImplParser::GobjectImplParser():mParser(json_parser_new()){}
    GobjectImplParser::~GobjectImplParser(){
        g_object_unref(mParser);
    }
    GobjectImplParser::operator JsonParser *(){
        return mParser;
    }
  }
}
