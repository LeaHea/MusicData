#include "Album.hpp"
                                                                                                                                           
Album::Album(){

  cachedTitle = cachedArtistID = cachedGenre = cachedYear = cachedAlbumID = cachedArtistID = cachedNumTracks = false;
  _title = _genre = _year = "";
  _albumID = _artistID = _numTracks = 0;
}

Album::Album(JSONDataObject *json){

  _title = json->valueForStringAttribute("title");
  std::cout<<_title<<std::endl;
  _genre = json->valueForStringAttribute("genres");
  std::cout<<_genre<<std::endl;
  _year = json->valueForStringAttribute("year");
  std::cout<<_year<<std::endl;
  _numTracks = json->valueForIntegerAttribute("num_tracks");
  std::cout<<_numTracks<<std::endl;
  _artistID = json->valueForIntegerAttribute("artist_id");
  std::cout<<_artistID<<std::endl;
  _albumID = json->valueForIntegerAttribute("album_id");
  std::cout<<_albumID<<std::endl;
}

Album::~Album(){

}

std::string Album::title(){
  if( cachedTitle )
    return _title;
  cachedTitle = true;
  return _title = valueForStringAttribute("title");
}

std::string Album::genre(){
  if( cachedGenre )
    return _genre;
  cachedGenre = true;
  return _genre = valueForStringAttribute("genres");
} 

std::string Album::year(){
  if( cachedYear )
    return _year;
  cachedYear = true;
  return _year = valueForStringAttribute("year");
} 

unsigned Album::albumID(){
  if( cachedAlbumID )
    return _albumID;
  cachedAlbumID = true;
  return _albumID = valueForIntegerAttribute("album_id");
}

unsigned Album::numTracks(){
  if( cachedNumTracks )
    return _numTracks;
  cachedNumTracks = true;
  return _numTracks = valueForIntegerAttribute("num_tracks");
}

unsigned Album::artistID(){
  if( cachedArtistID )
    return _artistID;
  cachedArtistID = true;
  return _artistID = valueForIntegerAttribute("artist_id");
} 

unsigned Album::numImages(){
  if( cachedNumImages )
    return _numImages;
  cachedNumImages = true;
  return _numImages = valueForIntegerAttribute("num_images");
} 

 
void Album::print(){
  std::cout << "Title: " << title() << std::endl;
  std::cout << "Genre: " << genre() << std::endl;
  std::cout << "Year: " << year() << std::endl;
  std::cout << "ArtistID: " << artistID() << std::endl;
  std::cout << "NumTracks: " << numTracks() << std::endl;
  std::cout << "AlbumID: " << albumID() << std::endl;
}

std::string Album::htmlString(){
  
  std::stringstream ssAlbum; 
  ssAlbum << "<b><font size= \"4\" color = \"green\">" << title()
	  << "</font></b></p>\n\t<ul><li><p>Number of Tracks: <font color = \"blue\">"
           << numTracks() << "</font></p></li>\n\t<li><p>Genres: <font color = \"blue\">"
           << genre() << "</font></p></li>\n\t<li><p>Year: <font color = \"blue\">"
	  << year() << "</font></li>\n\t</li></ul>";
  
  return ssAlbum.str();
  
}





