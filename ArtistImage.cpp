#include "JSONDataObject.hpp"
#include "Artist.hpp"

ArtistImage::ArtistImage(){

  _type = _uri = "";
  _width = _artistID = _height = 0;
  cachedType = cachedArtistID = cachedUri = cachedWidth = cachedHeight = false;
}

ArtistImage::ArtistImage(JSONDataObject *json){
  _width = json->valueForIntegerAttribute("width");
  _artistID = json->valueForIntegerAttribute("artist_id");
  _height = json->valueForIntegerAttribute("height");
  _uri = json->valueForStringAttribute("uri");
 
}

ArtistImage::~ArtistImage(){

}
  
std::string ArtistImage::uri(){
  if( cachedUri )
    return _uri;
  cachedUri = true;
  return _uri = valueForStringAttribute("uri");
}
std::string ArtistImage::type(){
  if( cachedType )
    return _type;
  cachedType = true;
  return _type = valueForStringAttribute("type");
}

unsigned ArtistImage::artistID(){
  if( cachedArtistID )
    return _artistID;
  cachedArtistID = true;
  return _artistID = valueForIntegerAttribute("artist_id");
}

unsigned ArtistImage::width(){
  if( cachedWidth )
    return _width;
  cachedWidth = true;
  return _width = valueForIntegerAttribute("width");
}

unsigned ArtistImage::height(){
  if( cachedHeight )
    return _height;
  cachedHeight = true;
  return _height = valueForIntegerAttribute("height");
}

void ArtistImage::print(){
  
  std::cout << "Type: " << type() << std::endl;
  std::cout << "ArtistID: " << artistID() << std::endl;
  std::cout << "Width: " << width() << std::endl;
  std::cout << "Height: " << height() << std::endl;
  std::cout << "URI: " << uri() << std::endl;
  
}

std::string ArtistImage::htmlString(){
  std::stringstream ssArtistImage;
 
  ssArtistImage << "<font size = 4>Image : </font><br> \n<ul>\n\t<li>ArtistID: <font color = \"blue\">"
		<< artistID() << "</font> </li>\n\t<li> Width: <font color = \"blue\">"
		<< width() << "</font></li>\n\t<li>Height: <font color = \"blue\">" 
		<< height() << "</font></li></ul>";
 
  return ssArtistImage.str();
}


