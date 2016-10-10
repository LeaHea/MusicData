#include "Artist.hpp"

Artist::Artist(){

  //  ArtistImage *_primaryImage, *_secondaryImage = new ArtistImage();
  //  Albums *_albums;

    _name = _realName = _profile = _numImages = "";
    _artistID = 0;

    cachedName = cachedRealName = cachedProfile = cachedNumImages = cachedArtistID = false;
}

Artist::Artist(JSONDataObject * json){
  _name = json->valueForStringAttribute("artist_name");
  _realName = json->valueForStringAttribute("real_name");
  _profile = json->valueForStringAttribute("profile");
  _numImages = json->valueForStringAttribute("num_images");
  _artistID = json->valueForIntegerAttribute("artist_id");
  
}

Artist::~Artist(){

}
 
std::string Artist::profile(){
    if( cachedProfile )
        return _profile;
    cachedProfile = true;
    return _profile = valueForStringAttribute("profile");
}

std::string Artist::artistName(){
    if( cachedName )
        return _name;
    cachedName = true;
    return _name = valueForStringAttribute("artist_name");
}

std::string Artist::realName(){
    if( cachedRealName )
        return _realName;
    cachedRealName = true;
    return _realName = valueForStringAttribute("real_name");
}

std::string Artist::numImages(){
    if( cachedNumImages )
        return _numImages;
    cachedNumImages = true;
    return _numImages = valueForStringAttribute("num_images");
}

unsigned Artist::artistID(){
    if( cachedArtistID )
        return _artistID;
    cachedArtistID = true;
    return _artistID = valueForIntegerAttribute("artist_id");
}


void Artist::print(){
  std::cout << "Profile: " << profile() << std::endl;
  std::cout << "Artist Name: " << artistName() << std::endl;
  std::cout << "Real Name: " << realName() << std::endl;
  std::cout << "Num Images: " << numImages() << std::endl;
  std::cout << "ArtistID: " << artistID() << std::endl; 
}

std::string Artist::htmlString(){
 
  std::stringstream ssArtist;
  
  ssArtist << "<p><b><font size= \"5\" >" << artistName() 
	   << "</font></b></p>\n\t<li><p>Number of images: <font color = \"blue\">" 
	   << numImages() << "</font></p></li>\n\t<li><p>Profile: <font color = \"blue\">" 
	   << profile() << "</font></p></li>\n\t<li><p>Real-name: <font color = \"blue\">" 
	   << realName() << "</font></p></li>\n\t</ul></li>";
 
  return ssArtist.str();
}
