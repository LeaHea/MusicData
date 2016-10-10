// Leah Headd
// JSON data item Class
                                                                                                                                   
#include "JSONDataItem.hpp"

JSONDataItem::JSONDataItem(){
  _attribute = _svalue = "";
  _ivalue = 0;
  hasReadAnItem = _isNumber = false;

}

void JSONDataItem::parseJSONItem(std::fstream &stream){

  char c;

  if( !(stream >> c) || c != '"'){
    std::cout << "Impropper JSON file...\n";
    exit(1);
    // exits if list is not formatted properly...                                                                                                                                                                                                                                                                                                                                                                                                   
  }

  while (stream.get(c) && c != ':'){
    _attribute = readQuotedString(stream);
  }
  if (c != ':' || !(stream >>c) ){

    std::cout << "Need a colon to separate item. \n";
    exit (1);
    //    exits if list is not formatted properly...                                                                                                                                                                                                                                                                                                                                                                                                  
  }


  if ( isdigit(c) ){

    _isNumber = true;

    stream.unget();
    stream >> _ivalue;

  }

  else{

    _isNumber = false;

    // gets stream if string                                                                                                                                                                        
    while (stream.get(c) && c != '"'){
      // tells to ignore whats after backslash                                                                                                                                                                                                                                                                                                                                                                                                        
      if ( c == '\\'){
        _svalue += c;
        stream >> c;
      }
      _svalue += c;

    }
  }


}

std::string JSONDataItem::readQuotedString(std::fstream &stream){
  // read until you get " (?) 
                                                                                                                          
char c;
  stream.unget();

  while (stream.get(c) && c != '"'){
    _attribute += c;
  }
  return _attribute;

}

std::string JSONDataItem::attribute(){
  return _attribute;
}

int JSONDataItem::integerValue(){
  return _ivalue;
}

std::string JSONDataItem::stringValue(){
  return _svalue;
}

bool &JSONDataItem::isNumber(){
  return _isNumber;
}

void JSONDataItem::print(){

  std::cout<< "Attribute: " << _attribute << std::endl;
  std::cout<< "svalue: " << _svalue << std::endl;
  if (_isNumber)
    std::cout<< "ivalue: " << _ivalue << std::endl;


}




