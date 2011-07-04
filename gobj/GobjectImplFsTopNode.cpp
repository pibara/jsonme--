#include "GobjectImplFsTopNode.hpp"
#include "GobjectImplError.hpp"
#include "GobjectImplNode.hpp"
#include "GobjectImplScalar.hpp"
namespace jsonme {
  namespace impl {
     GobjectImplFsTopNode::GobjectImplFsTopNode(std::string path):mRoot(0) {
       GobjectImplError lerror;
       json_parser_load_from_file (mParser,path.c_str(), lerror.errorp());
       if (lerror.error()) {
          throw jsonme::ParseError(lerror.error()->message);
       }
       mRoot=new GobjectImplNode(json_parser_get_root(mParser));
     } 
     GobjectImplFsTopNode::~GobjectImplFsTopNode() {
       delete mRoot;
     }
     jsonme::nodetype GobjectImplFsTopNode::nodetype() {
        return mRoot->nodetype();
     }
     Node GobjectImplFsTopNode::operator[](std::string name) {
        return (*mRoot)[name];
     }
     size_t GobjectImplFsTopNode::size() {
        return mRoot->size();
     }
     Node GobjectImplFsTopNode::operator[](size_t index) {
        return (*mRoot)[index];
     }
     GobjectImplFsTopNode::operator Scalar() {
        return (*mRoot);
     }
  }
}
