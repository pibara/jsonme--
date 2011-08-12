#include "GobjectImplKeys.hpp"
namespace jsonme {
                GobjectImplKeys::GobjectImplKeys(JsonNode* node) {
                  if (json_node_get_node_type(node) == JSON_NODE_OBJECT) {     
                   JsonObject *asObject=json_node_get_object(node);
                   if (asObject) {
                       GList *members=json_object_get_members(asObject);
                       if (members) {
                         for (GList *member=members;member;member=member->next) {
                            mKeys.push_back(std::string((char *) member->data));
                         }
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
