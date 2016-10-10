#include "Albums.hpp"

Albums::~Albums(){

}

int Albums::numAlbums(){
  return _listOfDataObjects->size();
}

void Albums::addAlbum(Album *album){
  _listOfDataObjects->push_back(album);
}

Album *Albums::albumWithID(unsigned int alID){ 
  for (std::vector<Album*>::iterator iter = listOfAlbums()->begin(); iter != listOfAlbums()->end(); ++iter ){
    if (alID == (*iter)->valueForIntegerAttribute("album_id"))   
      return (*iter);
  }
 
}

void Albums::loadAlbumsFromFile(std::string fileName){
    std::fstream albumStream;
    
    albumStream.open(fileName.c_str(), std::fstream::in); //filename?
    parseJSONArray(albumStream);
    albumStream.close();
}

void Albums::setTracksForAlbums(Tracks *tracks){
  for (int i =0 ; i < numAlbums(); i++){
    Tracks *tracksForAlbum = new Tracks;
    for (int j = 0; j < tracks->numTracks(); j++){

      if (tracks->listOfTracks()->at(j)->albumID() == listOfAlbums()->at(i)->albumID()){
	  tracksForAlbum->addTrack(tracks->listOfTracks()->at(j));
	}

      listOfAlbums()->at(i)->setTracks(tracksForAlbum);
    }   
    
  }
}

void Albums::setImagesForAlbums(AlbumImages *albumImages){
  for (int i =0 ; i < numAlbums(); i++){
    listOfAlbums()->at(i)->primaryImage() = new AlbumImage();
    listOfAlbums()->at(i)->secondaryImage() = new AlbumImage();

    for (int j = 0; j < albumImages->numAlbumImages(); j++){
      if (albumImages->listOfAlbumImages()->at(j)->albumID() == listOfAlbums()->at(i)->albumID()){

        if (albumImages->listOfAlbumImages()->at(j)->valueForStringAttribute("type") == "primary")
	  listOfAlbums()->at(i)->primaryImage() = albumImages->listOfAlbumImages()->at(j);
	    
        else
	  listOfAlbums()->at(i)->secondaryImage() = albumImages->listOfAlbumImages()->at(j);
	
      }      
    }
  }
}

std::string Albums::htmlString(){
  
  std::stringstream ssAlbums;
 
  ssAlbums << "<ol>\n";

  for (std::vector<Album*>::iterator iter = listOfAlbums()->begin(); iter !=listOfAlbums()->end(); ++iter ){    
    std::fstream HTMLtemplate;
    std::ofstream HTML;
    std::string line;
    std::stringstream file;
   
    HTMLtemplate.open("album_template.html"); // HTML file to read                               
    file.str("");
    file << "./html_albums/album" << (*iter)->albumID() << ".html"; // HTML file to write

    std::string stringHTML = file.str();
    char * charHTML = (char *) stringHTML.c_str();

    HTML.open(charHTML);
        
    while (!HTMLtemplate.eof())
      {
	HTML << "\n";

	getline(HTMLtemplate, line);

	if ( line == "    <title><% album_name %></title>"){	
	  HTML << "<title>" << (*iter)->title() << "</title>";
	}
	
	if ( line == "<% album_details %>"){
	  HTML << (*iter)->htmlString();
	  HTML << "<font size = \"4\"><br><b> Images </font> </b><br>\n";
	  
	  if ((*iter)->primaryImage()->width() != 0 )
	    HTML << (*iter)->primaryImage()->htmlString();
	  else
	    HTML << (*iter)->secondaryImage()->htmlString();

  
	  HTML << "<font size = \"4\"><br><b> TrackList </font> </b><br>\n";
	  HTML << (*iter)->tracks()->htmlString();

	}
	
	else HTML << line;
      }
    HTML.close();

    ssAlbums << (*iter)->htmlString();
    
    ssAlbums << "<font size = \"4\"><br><b> Images </font> </b><br>\n";
    if ((*iter)->primaryImage()->width() != 0 )	
      ssAlbums << (*iter)->primaryImage()->htmlString();
    else
      ssAlbums << (*iter)->secondaryImage()->htmlString();
    
    ssAlbums << "<font size = \"4\"><br><b> TrackList </font> </b><br>\n";
    ssAlbums << (*iter)->tracks()->htmlString();
   
  }
  ssAlbums << "\n</ol>";
  
  return ssAlbums.str();
}

void Albums::runAsserts(){

}
