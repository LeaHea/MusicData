#include "JSONArray.hpp"
#include "AlbumImages.hpp"


AlbumImages::~AlbumImages(){ 

}
  
int AlbumImages::numAlbumImages(){ 
  return _listOfDataObjects->size();
}

void AlbumImages::addAlbumImage(AlbumImage *albumImage){ 
  _listOfDataObjects->push_back(albumImage);
}

AlbumImage *AlbumImages::albumImageWithID(unsigned int alID){ 
  for (std::vector<AlbumImage*>::iterator iter = listOfAlbumImages()->begin(); iter != listOfAlbumImages()->end(); ++iter ){
    if (alID == (*iter)->valueForIntegerAttribute("album_id"))
      return (*iter);
  }
}

void AlbumImages::loadAlbumImagesFromFile(std::string fileName){ 
  std::fstream albumImageStream;
  albumImageStream.open(fileName.c_str(), std::fstream::in); //filename?                                  
  parseJSONArray(albumImageStream);
  albumImageStream.close();

}

std::string AlbumImages::htmlString(){ 

  std::stringstream ssAlbumImages;

  ssAlbumImages << "\n";

  ssAlbumImages << "<ol>\n";
  for (std::vector<AlbumImage*>::iterator iter = listOfAlbumImages()->begin(); iter !=listOfAlbumImages()->end(); ++iter ){
    ssAlbumImages << "\na AlbumImage?\n";
    ssAlbumImages << (*iter)->htmlString();
  }
  ssAlbumImages << "\n</ol>";
 
  return ssAlbumImages.str();
}
  
void runAsserts(){

}

