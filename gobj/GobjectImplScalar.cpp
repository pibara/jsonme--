#include "GobjectImplScalar.hpp"
#include <boost/lexical_cast.hpp>
namespace jsonme {
  namespace impl {
    GobjectImplScalar::GobjectImplScalar(JsonNode  * const node):mNode(node),mValue(){
       if (mNode && JSON_NODE_HOLDS_VALUE(mNode)) {
          json_node_get_value(mNode,&mValue);
       }
    }
    jsonme::scalartype GobjectImplScalar::scalartype() const {
       switch (json_node_get_value_type(mNode)) {
         case G_TYPE_BOOLEAN :
             return jsonme::BOOL;
         case G_TYPE_INT:
         case G_TYPE_UINT:
         case G_TYPE_LONG:
         case G_TYPE_ULONG:
         case G_TYPE_INT64:
             return jsonme::INTEGER;
         case G_TYPE_FLOAT:
         case G_TYPE_DOUBLE:
             return jsonme::FLOAT;
         case G_TYPE_STRING:
             return jsonme::STRING;
         default:
             return jsonme::NULLVAL;
       }
    }
    GobjectImplScalar::operator long double() const {
       switch (json_node_get_value_type(mNode)) {
          case G_TYPE_FLOAT: return g_value_get_float(&mValue);
          case G_TYPE_DOUBLE: return g_value_get_double(&mValue);
          case G_TYPE_BOOLEAN: return g_value_get_boolean(&mValue) ? 1.0 : 0.0;
          case G_TYPE_INT: return g_value_get_int(&mValue) * 1.0;
          case G_TYPE_UINT: return g_value_get_uint(&mValue) * 1.0;
          case G_TYPE_LONG: return g_value_get_long(&mValue) * 1.0;
          case G_TYPE_INT64: return g_value_get_int64(&mValue) * 1.0;
          case G_TYPE_ULONG: return  g_value_get_ulong(&mValue) * 1.0;
          case G_TYPE_STRING: return boost::lexical_cast<long double>(g_value_get_string(&mValue));
          default: return 0.0;
       }
    }
    GobjectImplScalar::operator long long() const {
       switch (json_node_get_value_type(mNode)) {
         case G_TYPE_FLOAT: return 0;  //Fixme, probably an exception is in place.
         case G_TYPE_DOUBLE: return 0; //Fixme, probably an exception is in place.
         case G_TYPE_BOOLEAN: return g_value_get_boolean(&mValue) ? 1 : 0;
         case G_TYPE_INT: return g_value_get_int(&mValue);
         case G_TYPE_UINT: return g_value_get_uint(&mValue);
         case G_TYPE_LONG: return g_value_get_long(&mValue);
         case G_TYPE_INT64: return g_value_get_int64(&mValue);
         case G_TYPE_ULONG: return  g_value_get_ulong(&mValue);
         case G_TYPE_STRING: return boost::lexical_cast<long long>(g_value_get_string(&mValue)); 
         default: return 0;
       }
    }
    GobjectImplScalar::operator std::string() const {
       if (! mNode) {
          return "";
       }
       switch (json_node_get_value_type(mNode)) {
          case G_TYPE_FLOAT: return boost::lexical_cast<std::string>(g_value_get_float(&mValue));
          case G_TYPE_DOUBLE: return boost::lexical_cast<std::string>(g_value_get_double(&mValue));
          case G_TYPE_BOOLEAN: return g_value_get_boolean(&mValue) ? "TRUE" : "FALSE";
          case G_TYPE_INT: return  boost::lexical_cast<std::string>(g_value_get_int(&mValue));
          case G_TYPE_UINT: return  boost::lexical_cast<std::string>(g_value_get_uint(&mValue));
          case G_TYPE_LONG: return  boost::lexical_cast<std::string>(g_value_get_long(&mValue));
          case G_TYPE_INT64: return  boost::lexical_cast<std::string>(g_value_get_int64(&mValue));
          case G_TYPE_ULONG: return  boost::lexical_cast<std::string>(g_value_get_ulong(&mValue));
          case G_TYPE_STRING: return g_value_get_string(&mValue);
          default: return "";
       }
    }
    GobjectImplScalar::operator bool() const {
      switch (json_node_get_value_type(mNode)) {
        case G_TYPE_FLOAT: return false;
        case G_TYPE_DOUBLE: return false;
        case G_TYPE_BOOLEAN: return g_value_get_boolean(&mValue);
        case G_TYPE_INT: return g_value_get_int(&mValue)==0 ? false : true;
        case G_TYPE_UINT: return g_value_get_uint(&mValue)==0 ? false : true;
        case G_TYPE_LONG: return g_value_get_long(&mValue)==0 ? false : true;
        case G_TYPE_ULONG: return g_value_get_ulong(&mValue)==0 ? false : true;
        case G_TYPE_INT64: return g_value_get_int64(&mValue)==0 ? false : true;
        case G_TYPE_STRING: return std::string(g_value_get_string(&mValue)) == "" ? false: true; 
        default: return false;
      }
    }
    bool GobjectImplScalar::isNull() const {
       if (json_node_is_null(mNode)) {
         return true;
       }
       return false;
    }
  }  
}
