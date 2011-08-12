#ifndef _JSONME_NULLKEYS_HPP
#define _JSONME_NULLKEYS_HPP
namespace jsonme {
          class NullKeys: public AbstractKeys {
             public:
                std::string operator[](size_t index) const { return "";}
                size_t size() const{ return 0;}
          };
}
#endif
