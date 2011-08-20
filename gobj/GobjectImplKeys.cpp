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
#include "GobjectImplKeys.hpp"
namespace jsonme {
                //Constructor.
                GobjectImplKeys::GobjectImplKeys(JsonNode* node):mKeys() {
                  Only object type json nodes have keys.
                  if (json_node_get_node_type(node) == JSON_NODE_OBJECT) {     
                   JsonObject *asObject=json_node_get_object(node);
                   if (asObject) {
                       //get all propertis the object has.
                       GList *members=json_object_get_members(asObject);
                       if (members) {
                         //Add each key to our vector.
                         for (GList *member=members;member;member=member->next) {
                            mKeys.push_back(std::string((char *) member->data));
                         }
                         //Do some cleanup.
                         g_list_free(members);
                       }
                   }
                  }
                }
                std::string GobjectImplKeys::operator[](size_t index) const { return mKeys[index];}
                size_t GobjectImplKeys::size() const{ 
                   return mKeys.size();
                }
}
