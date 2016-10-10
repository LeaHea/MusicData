#include <cstdlib>
#include "JSONArray.hpp"
#include "Tracks.hpp"

JSONArray::JSONArray(){

  _listOfDataObjects = new std::vector<JSONDataObject*>;
  
}
JSONArray::~JSONArray(){
  _listOfDataObjects->clear();
}

int JSONArray::numJSONObjects(){
  return _listOfDataObjects->size();
}

void JSONArray::parseJSONArray(std::fstream &stream){
  
  char c;

  if (!(stream >> c) || c != '[' ){
      std::cout << "\nMissing starting bracket " << std::endl;
      exit(1);
    }
  
  stream.unget();
  
  while (stream.get (c) && c != ']'){

    JSONDataObject *dObject = jsonObjectNode();
          
    dObject->parseFromJSONstream(stream);
    _listOfDataObjects->push_back(dObject);
    
  }

  //  print();

}

void JSONArray::print(){
  for (std::vector<JSONDataObject*>::iterator iter = _listOfDataObjects->begin(); iter !=_listOfDataObjects->end(); ++iter )
    (*iter)->print();
}

