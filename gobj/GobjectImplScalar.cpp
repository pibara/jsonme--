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
#include "GobjectImplScalar.hpp"
#include <boost/lexical_cast.hpp>
namespace jsonme {
  namespace impl {
    //Constructor.
    GobjectImplScalar::GobjectImplScalar(JsonNode  * const node):mNode(node),mValue(){
       if (mNode && ((json_node_get_node_type(((mNode))) == (JSON_NODE_VALUE)))) {
          json_node_get_value(mNode,&mValue); //Fetch the value if possible.
       }
    }
    GobjectImplScalar::~GobjectImplScalar() throw() {
      g_value_unset(&mValue); //Cleanup after us.
    }
    //Map glib json lib enum to JsonMe++ enum.
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
    //Cast any type of scalar to a reasonable float.
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
    //Cast any type of scalar to a reasonable int.
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
    //Cast any type of scalar to a reasonable string.
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
    //Cast any type of scalar to a reasonable bool.
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
    GobjectImplScalar & GobjectImplScalar::operator=(long double){
       //FIXME
       return *this;
    }
    GobjectImplScalar & GobjectImplScalar::operator=(long long){
       //FIXME
       return *this;
    }
    GobjectImplScalar & GobjectImplScalar::operator=(bool){
       //FIXME
       return *this;
    }
    GobjectImplScalar & GobjectImplScalar::operator=(std::string){
       //FIXME
       return *this;
    }
  }  
}
