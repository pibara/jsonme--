#ifndef _JSONME_GOBJIMPLKEYS_HPP
#define _JSONME_GOBJIMPLKEYS_HPP
#include "../json-me.hpp"
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include <string>
#include <vector>
#include <iostream>
namespace jsonme {
          class GobjectImplKeys: public AbstractKeys {
                std::vector<std::string> mKeys;
             public:
                GobjectImplKeys(JsonNode* node); 
                ~GobjectImplKeys() throw() {}
                std::string operator[](size_t index) const;
                size_t size() const;
          };
}
#endif
