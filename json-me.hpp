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
      virtual jsonme::scalartype scalartype() const=0;
      virtual operator long double() const=0;
      virtual operator long long() const=0;
      virtual operator std::string() const=0;
      virtual operator bool() const=0;
      virtual bool isNull() const=0;
  };
  //A value semantics proxy to the implementation specific scalar.
  class Scalar;
  class NullScalar: public AbstractScalar {
        public:
          jsonme::scalartype scalartype() const { return NULLVAL;}
          operator long double() const { return 0;}
          operator long long() const { return 0;}
          operator std::string() const { return "";}
          operator bool() const { return false;}
          bool isNull() const { return true;}
  };  
  class Scalar: public AbstractScalar  {
      boost::shared_ptr<AbstractScalar> mScalar;
    public:
      Scalar();
      Scalar(AbstractScalar *scalar);
      jsonme::scalartype  scalartype() const;
      operator long double() const;
      operator long long() const;
      operator std::string() const;
      operator bool() const;
      bool isNull() const;
  };
  //A json node is either an object, an array or a scalar.
  typedef enum {OBJECT,ARRAY,SCALAR,INVALID} nodetype;

  class AbstractKeys {
    public:
      virtual std::string operator[](size_t index) const=0;
      virtual size_t size() const=0;
  };
  class NullKeys: public AbstractKeys {
    public:
     std::string operator[](size_t index) const { return "";}
     size_t size() const{ return 0;}
  };
  class Node;
  //The node has a type, and depending on its type can:
  //* SCALAR: be cast to a Scalar
  //* ARRAY: have its size queried and have access to indexed sub node's.
  //* OBJECT: have its members looked up by name. 
  class AbstractNode {
    public:
        virtual ~AbstractNode(){}
        virtual AbstractKeys & keys()=0;
        virtual jsonme::nodetype nodetype() const=0;
        virtual Node operator[](std::string const &  name) const=0;
        virtual size_t size() const=0;
        virtual Node operator[](size_t index) const=0;
        virtual operator Scalar() const=0;
  };
  //A value semantics proxy to the implementation specific node.
  class Node: public AbstractNode, public AbstractScalar {
    public:
      Node();
    private:
      class NullNode: public AbstractNode {
          NullKeys mNullKeys;
        public:
          AbstractKeys & keys() { return mNullKeys;}
          jsonme::nodetype nodetype() const {return INVALID;}
          Node operator[](std::string const & name) const { return Node();}
          size_t size() const { return 0;}
          Node operator[](size_t index) const { return Node();}
          operator Scalar() const { return Scalar(); }
      };
      boost::shared_ptr<AbstractNode> mNode;
    public:
      Node(AbstractNode *node);
      AbstractKeys & keys();
      jsonme::nodetype nodetype() const;
      Node operator[](std::string const & name) const;
      Node operator[](char const * const) const;
      size_t size() const;
      Node operator[](size_t index) const ;
      jsonme::scalartype scalartype() const;
      operator Scalar() const;
      operator long double() const;
      operator long long() const;
      operator std::string() const;
      operator bool() const;
      bool isNull() const;
  };
  //The impl namespace should be non of your concern.
  namespace impl {
    class AbstractLibImpl {
      public:
        virtual ~AbstractLibImpl(){}
        virtual AbstractNode *parse(std::string const &  jsonstring) const =0;
        virtual AbstractNode *parseFile(std::string const & jsonstring) const=0;
    };
  };
  //Wrapper class for an available low level json library.
  class JsonMeLib {
      jsonme::impl::AbstractLibImpl *mLibImpl;
    public:
      JsonMeLib();
      ~JsonMeLib();
      Node parse(std::string const & jsonstring) const;
      Node parseFile(std::string const & path) const;
  };
}


#endif
