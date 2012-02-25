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
  //A scalar can be a number (float or integer), a string, a bool or a null value.
  typedef enum {FLOAT,INTEGER,STRING,BOOL,NULLVAL} scalartype;
  //A json node is either an object, an array or a scalar.
  typedef enum {OBJECT,ARRAY,SCALAR,INVALID} nodetype;  
  //
  class ParseError: public std::exception {
      std::string mMessage;
    public:
      ParseError(std::string msg);
      ~ParseError() throw();
      const char * what() const throw();
  }; 
  class JsonStructureError: public std::exception {
      std::string mMessage;
    public:
      JsonStructureError(std::string msg);
      ~JsonStructureError() throw();
      const char * what() const throw();
  };
  //The scalar has a type and can be cast to that type. Casting to any other type shall
  //result in a lexical conversion if possible or a default null value if not.
  class AbstractScalar {
    public:
      virtual ~AbstractScalar() throw() {}
      virtual jsonme::scalartype scalartype() const=0;
      virtual operator long double() const=0;
      virtual operator long long() const=0;
      virtual operator std::string() const=0;
      virtual operator bool() const=0;
      virtual bool isNull() const=0;
      virtual AbstractScalar & operator=(long double in)=0;
      virtual AbstractScalar & operator=(long long in)=0;
      virtual AbstractScalar & operator=(std::string in)=0;
      virtual AbstractScalar & operator=(bool in)=0;
  };
  class AbstractNode;
  //A value semantics proxy to the implementation specific scalar.
  class Scalar: public AbstractScalar  {
      boost::shared_ptr<AbstractScalar> mScalar;
    public:
      //Scalar();
      ~Scalar() throw() {}
      Scalar(AbstractScalar *scalar);
      Scalar(AbstractNode const *parent);
      jsonme::scalartype  scalartype() const;
      operator long double() const;
      operator long long() const;
      operator std::string() const;
      operator bool() const;
      bool isNull() const;
      Scalar & operator=(long double in);
      Scalar & operator=(long long in);
      Scalar & operator=(std::string in);
      Scalar & operator=(bool in);
  };

  class AbstractKeys {
    public:
      virtual ~AbstractKeys() throw() {}
      virtual std::string operator[](size_t index) const=0;
      virtual size_t size() const=0;
  };
  //Forward declaration of Node needed for AbstractNode::operator[] 
  class Node;
  //The base interface for a Node.
  //The node has a type, and depending on its type can:
  //* (SCALAR) : be cast to a Scalar
  //* (ARRAY)  : have its size queried and have access to indexed sub node's.
  //* (OBJECT) : have its members looked up by name. 
  class AbstractNode {
    public:
        virtual ~AbstractNode() throw() {}
        virtual AbstractKeys & keys()=0;
        virtual jsonme::nodetype nodetype() const=0;
        virtual Node operator[](std::string const &  name) const=0;
        virtual size_t size() const=0;
        virtual Node operator[](size_t index) const=0;
        virtual operator Scalar() const=0;
        void autoVivivicate(jsonme::nodetype) {} //Should be refactored, first get autovivification working the non-clean way.
  };
  //A value semantics proxy to the implementation specific node.
  class Node: public AbstractNode, public AbstractScalar {
      boost::shared_ptr<AbstractNode> mNode;
    public:
     // Node();
      Node(AbstractNode *node);
      Node(AbstractNode *node,AbstractNode const *parent,std::string key);
      Node(AbstractNode *node,AbstractNode const *parent,size_t index);
      ~Node() throw() {}
      AbstractKeys & keys();
      jsonme::nodetype nodetype() const;
      Node operator[](std::string const & name) const;
      Node operator[](char const * const) const;
      size_t size() const;
      Node operator[](size_t index) const ;
      Node operator[](int index) const ; //For literal use only
      jsonme::scalartype scalartype() const;
      operator Scalar() const;
      operator long double() const;
      operator long long() const;
      operator std::string() const;
      operator bool() const;
      bool isNull() const;
      Node & operator=(long double in);
      Node & operator=(long long in);
      Node & operator=(std::string in);
      Node & operator=(bool in);
  };
  //The interface for the library object.
  class AbstractLibImpl {
      public:
        virtual ~AbstractLibImpl() throw() {}
        virtual Node parse(std::string const &  jsonstring) const =0;
        virtual Node parseFile(std::string const & jsonstring) const=0;
        virtual Node object() const=0;
        virtual Node array() const=0;
  };
  //A value semantics proxy to the library implementation.
  class JsonMeLib : public AbstractLibImpl {
      boost::shared_ptr<AbstractLibImpl> mLibImpl;
    public:
      JsonMeLib();
      ~JsonMeLib() throw();
      Node parse(std::string const & jsonstring) const;
      Node parseFile(std::string const & path) const;
      Node object() const;
      Node array() const;
  };
}


#endif
