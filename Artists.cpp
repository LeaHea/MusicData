#include "Artists.hpp"


Artists::~Artists(){

}

int Artists::numArtists(){
  return _listOfDataObjects->size();
}

void Artists::addArtist(Artist *artist){
  _listOfDataObjects->push_back(artist);
}

Artist *Artists::artistWithID(unsigned int aID){
  for (std::vector<Artist*>::iterator iter = listOfArtists()->begin(); iter != listOfArtists()->end(); ++iter )
    if (aID == (*iter)->valueForIntegerAttribute("artist_id"))
      return (*iter);
}

void Artists::setAlbumsForArtists(Albums *albums){
  for (int i =0 ; i < numArtists(); i++){
    Albums *albumsForArtist = new Albums;
    for (int j = 0; j < albums->numAlbums(); j++){
      if (albums->listOfAlbums()->at(j)->artistID() == listOfArtists()->at(i)->artistID())
        albumsForArtist->addAlbum(albums->listOfAlbums()->at(j));
    }  
    listOfArtists()->at(i)->setAlbums(albumsForArtist);
  }
}

void Artists::setImagesForArtists(ArtistImages *artistImages){
  for (int i =0 ; i < numArtists(); i++){
    listOfArtists()->at(i)->primaryImage() = new ArtistImage();
    listOfArtists()->at(i)->secondaryImage() = new ArtistImage();
    for (int j = 0; j < artistImages->numArtistImages(); j++){
      if (artistImages->listOfArtistImages()->at(j)->artistID() == listOfArtists()->at(i)->artistID()){
	if (artistImages->listOfArtistImages()->at(j)->valueForStringAttribute("type") == "primary")
	  listOfArtists()->at(i)->primaryImage() = artistImages->listOfArtistImages()->at(j);
	else
	  listOfArtists()->at(i)->secondaryImage() = artistImages->listOfArtistImages()->at(j);
      }
    }
  }
}

void Artists::loadArtistsFromFile(std::string fileName){
    std::fstream artStream;
    artStream.open(fileName.c_str(), std::fstream::in);
    parseJSONArray(artStream);
    artStream.close();
}

std::string Artists::htmlString(){

  std::stringstream ssArtists;
  
  ssArtists << "\n";
  ssArtists << "<font size = \"6\"><b> Artists </font> </b><br>\n";

  for (std::vector<Artist*>::iterator iter = listOfArtists()->begin(); iter !=listOfArtists()->end(); ++iter ){
    ssArtists << (*iter)->htmlString();
    ssArtists << "<font size = \"4\"><br><b> Images </font> </b><br><br\n";
 
    int numImages = std::stoi((*iter)->numImages());

    if ((*iter)->primaryImage()->width() != 0 )
      ssArtists << (*iter)->primaryImage()->htmlString();
    else
      ssArtists << (*iter)->secondaryImage()->htmlString();

    ssArtists << "<font size = \"5\"><b> Album List </font> </b><br>\n";  
    ssArtists << (*iter)->albums()->htmlString();
  }

  std::fstream HTMLtemplate;
  std::fstream HTML;
  std::string line;


  HTMLtemplate.open("artists_template.html"); // HTML file to read                                                                                                                                    
  HTML.open("artists.html"); // HTML file to write                                                                                                                                                    

  while(!HTMLtemplate.eof())
    {
      HTML << "\n";
      getline(HTMLtemplate, line);

      if ( line == "<% artists %>")
	HTML << ssArtists.str();
      else
        HTML << line;
    }

  HTML.close();
  
  return ssArtists.str();
  
}

void Artists::runAsserts(){

}
