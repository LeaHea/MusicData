#include "JSONDataObject.hpp"
#include "AlbumImage.hpp"

AlbumImage::AlbumImage(){
  
  _type = _uri = "";
  _width = _albumID = _height = 0;
  cachedType = cachedAlbumID = cachedWidth = cachedUri = cachedHeight = false;
}

AlbumImage::AlbumImage(JSONDataObject *json){
  
  _type = json -> valueForStringAttribute("type");
  _uri = json -> valueForStringAttribute("uri");
  _albumID = json -> valueForIntegerAttribute("album_id");
  _width = json -> valueForIntegerAttribute("width");
  _height = json -> valueForIntegerAttribute("height");
  
}

AlbumImage::~AlbumImage(){

}

std::string AlbumImage::type(){
  if( cachedType )
    return _type;
  cachedType = true;
  return _type = valueForStringAttribute("type");

}
std::string AlbumImage::uri(){
  if( cachedUri )
    return _uri;
  cachedUri = true;
  return _uri = valueForStringAttribute("uri");

}

unsigned AlbumImage::albumID(){
  if( cachedAlbumID )
    return _albumID;
  cachedAlbumID = true;
  return _albumID = valueForIntegerAttribute("album_id");

}

unsigned AlbumImage::width(){
  if( cachedWidth )
    return _width;
  cachedWidth = true;
  return _width = valueForIntegerAttribute("width");
}

unsigned AlbumImage::height(){
  if( cachedHeight )
    return _height;
  cachedHeight = true;
  return _height = valueForIntegerAttribute("height");
}

void AlbumImage::print(){
  
  std::cout << "Type: " << type() << std::endl;
  std::cout << "AlbumID: " << albumID() << std::endl;
  std::cout << "Width: " << width() << std::endl;
  std::cout << "Height: " << height() << std::endl;
  std::cout << "uri: " << uri() << std::endl;
  
}

std::string AlbumImage::htmlString(){

  std::stringstream ssAlbumImage;
  ssAlbumImage << "<font size = 4><br> Image : </font><br> \n<ul>\n\t<li> AlbumID: <font color = \"blue\">"
	       << albumID() << "</font> </li>\n\t<li> Width: <font color = \"blue\">"
	       << width() << "</font></li>\n\t<li>Height: <font color = \"blue\">"
	       << height() << "</font></li><br></ul>";



  return ssAlbumImage.str();
}
