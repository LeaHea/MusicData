#include "JSONDataObject.hpp"
 

JSONDataObject::JSONDataObject(){
  _listOfDataItems = new std::vector <JSONDataItem*>;

}

JSONDataObject::~JSONDataObject(){
  _listOfDataItems->clear();

}

void JSONDataObject::parseFromJSONstream(std::fstream &stream){
  char c;

  if (!(stream >> c) || c != '{' ){
      std::cout << "\nMissing starting brace " << std::endl;
      exit(1);
    }
  
  stream.unget();
     
  while (stream.get (c) && c != '}'){
      JSONDataItem *dItem = new JSONDataItem;  
      
      dItem->parseJSONItem(stream);
      _listOfDataItems->push_back(dItem);
    
    }
}

void JSONDataObject::print(){
  for (std::vector<JSONDataItem*>::iterator iter = _listOfDataItems->begin(); iter !=_listOfDataItems->end(); ++iter )
    (*iter)->print();    
}

std::string JSONDataObject::valueForStringAttribute(std::string s){
  for (std::vector<JSONDataItem*>::iterator iter = _listOfDataItems->begin(); iter !=_listOfDataItems->end(); ++iter )
    if (s == (*iter)->attribute())
      return (*iter)->stringValue();
}

int JSONDataObject::valueForIntegerAttribute(std::string s){
  for (std::vector<JSONDataItem*>::iterator iter = _listOfDataItems->begin(); iter !=_listOfDataItems->end(); ++iter )
     if (s == (*iter)->attribute())
       return(*iter)->integerValue();

}
