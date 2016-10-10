#include "Track.hpp"


Track::Track(){

  cachedArtistName = cachedTitle = cachedAlbumName = cachedDuration = cachedPosition = false; 
  _artistName = _title = _albumName = _duration = _position = "";
  _albumID = 0;
}

Track::Track(JSONDataObject* json){
  _artistName = json->valueForStringAttribute("artist_name");
  _title = json->valueForStringAttribute("title");
  _albumName = json->valueForStringAttribute("album_name");
  _duration = json->valueForIntegerAttribute("duration");
  _position = json->valueForIntegerAttribute("position");

}

Track::~Track(){
  
}

std::string Track::title() {
  if( cachedTitle )
    return _title;
  cachedTitle = true;
  return _title = valueForStringAttribute("title");
}

std::string Track::artistName() { 
  if( cachedArtistName )
    return _artistName;
  cachedArtistName = true;
  return _artistName = valueForStringAttribute("artist_name");
}

std::string Track::albumName()  {   
  if( cachedAlbumName )
    return _albumName;
  cachedAlbumName = true;
  return _albumName = valueForStringAttribute("album_name");
}

std::string Track::duration()  { 
  if( cachedDuration)
    return _duration;
  cachedDuration = true;
  return _duration = valueForStringAttribute("duration");
}

std::string Track::position()  {   
  if( cachedPosition )
    return _position;
  cachedPosition = true;
  return _position = valueForStringAttribute("position");
}

unsigned Track::albumID()  { 
  if( cachedAlbumID )
    return _albumID;
  cachedAlbumID = true;
  return _albumID = valueForIntegerAttribute("album_id");
}

void Track::print(){

  std::cout << "Title: " << title() << std::endl;
  std::cout << "Artist Name: " << artistName() << std::endl;
  std::cout << "Album Name: " << albumName() << std::endl;
  std::cout << "Duration: " << duration() << std::endl;
  std::cout << "Position: " << position() << std::endl;
  std::cout << "AlbumID: " << albumID() << std::endl;

}

std::string Track::htmlString(){

  std::stringstream ssTrack;
  
  ssTrack << "\n<p><b><li><font color = \"red\">" << title() << "</font></li></b></p>\n\t<p>Duration: <font color = \"blue\">"
          << duration() << "</font></p>\n\t<p>Position: <font color = \"blue\">"
          << position() << "</font></p>\n\t</p>";

  return ssTrack.str();  

}

