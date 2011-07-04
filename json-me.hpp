#ifndef _JSONME_HPP
#define _JSONME_HPP
#include <string>
#include <boost/shared_ptr.hpp>
//The json-me library is a simple wrapper library for making the parsing of json input
//with a known structure easy in C++. The interface used to wrap the low level json library
//is aimed at making no assumptions on the way the low level library is implemented in order 
//to allow multiple bindings to exist for any json library desired. This file holds the generic
//interface that you as a user should use.
namespace jsonme {
  class ParseError: public std::exception {
      std::string mMessage;
    public:
      ParseError(std::string msg):mMessage(msg){}
      ~ParseError() throw() {}
      const char * what() const throw() {
         return mMessage.c_str();
      }
  }; 
  //A scalar can be a number (float or integer), a string, a bool or a null value.
  typedef enum {FLOAT,INTEGER,STRING,BOOL,NULLVAL} scalartype;
  //The scalar has a type and can be cast to that type. Casting to any other type shall
  //result in a lexical conversion if possible or a default null value if not.
  class AbstractScalar {
    public:
      virtual ~AbstractScalar(){}
      virtual jsonme::scalartype scalartype()=0;
      virtual operator long double()=0;
      virtual operator long long()=0;
      virtual operator std::string()=0;
      virtual operator bool()=0;
      virtual bool isNull()=0;
  };
  //A value semantics proxy to the implementation specific scalar.
  class Scalar: public AbstractScalar  {
      boost::shared_ptr<AbstractScalar> mScalar;
    public:
      Scalar(AbstractScalar *scalar);
      jsonme::scalartype scalartype();
      operator long double();
      operator long long();
      operator std::string();
      operator bool();
      bool isNull();
  };
  //A json node is either an object, an array or a scalar.
  typedef enum {OBJECT,ARRAY,SCALAR,INVALID} nodetype;

  class Node;
  //The node has a type, and depending on its type can:
  //* SCALAR: be cast to a Scalar
  //* ARRAY: have its size queried and have access to indexed sub node's.
  //* OBJECT: have its members looked up by name. 
  class AbstractNode {
    public:
        virtual ~AbstractNode(){}
        virtual jsonme::nodetype nodetype()=0;
        virtual Node operator[](std::string name)=0;
        virtual size_t size()=0;
        virtual Node operator[](size_t index)=0;
        virtual operator Scalar()=0;
  };
  //A value semantics proxy to the implementation specific node.
  class Node: public AbstractNode, public AbstractScalar {
      boost::shared_ptr<AbstractNode> mNode;
    public:
      Node(AbstractNode *node);
      jsonme::nodetype nodetype();
      Node operator[](std::string name);
      Node operator[](const char *);
      size_t size();
      Node operator[](size_t index);
      jsonme::scalartype scalartype();
      operator Scalar();
      operator long double();
      operator long long();
      operator std::string();
      operator bool();
      bool isNull();
  };
  //The impl namespace should be non of your concern.
  namespace impl {
    class AbstractLibImpl {
      public:
        virtual ~AbstractLibImpl(){}
        virtual AbstractNode *parse(std::string jsonstring)=0;
        virtual AbstractNode *parseFile(std::string jsonstring)=0;
    };
  };
  //Wrapper class for an available low level json library.
  class JsonMeLib {
      jsonme::impl::AbstractLibImpl *mLibImpl;
    public:
      JsonMeLib();
      ~JsonMeLib();
      Node parse(std::string jsonstring);
      Node parseFile(std::string path);
  };
}


#endif
