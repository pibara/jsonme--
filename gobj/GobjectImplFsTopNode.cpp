#include "GobjectImplFsTopNode.hpp"
#include "GobjectImplError.hpp"
#include "GobjectImplNode.hpp"
#include "GobjectImplScalar.hpp"
namespace jsonme {
  namespace impl {
     GobjectImplFsTopNode::GobjectImplFsTopNode(std::string const & path):mParser(),mRoot(0) {
       GobjectImplError lerror;
       json_parser_load_from_file (mParser,path.c_str(), lerror.errorp());
       if (lerror.error()) {
          throw jsonme::ParseError(lerror.error()->message);
       }
       mRoot=new GobjectImplNode(json_parser_get_root(mParser));
     } 
     GobjectImplFsTopNode::~GobjectImplFsTopNode() throw() {
       delete mRoot;
     }
     jsonme::nodetype GobjectImplFsTopNode::nodetype() const {
        return mRoot->nodetype();
     }
     Node GobjectImplFsTopNode::operator[](std::string const & name) const {
        return (*mRoot)[name];
     }
     size_t GobjectImplFsTopNode::size() const {
        return mRoot->size();
     }
     Node GobjectImplFsTopNode::operator[](size_t index) const {
        return (*mRoot)[index];
     }
     GobjectImplFsTopNode::operator Scalar() const {
        return (*mRoot);
     }
     AbstractKeys &GobjectImplFsTopNode::keys() { 
        return mRoot->keys();
     }
  }
}
