#include "ArtistImages.hpp"

ArtistImages::~ArtistImages(){ 

}
  
int ArtistImages::numArtistImages(){ 
  return _listOfDataObjects->size();
}

void ArtistImages::addArtistImage(ArtistImage *artistImage){ 

}

ArtistImage *artistImageWithID(unsigned int tID){ 

}

void ArtistImages::loadArtistImagesFromFile(std::string fileName){ 
  std::fstream artistImageStream;
  artistImageStream.open(fileName.c_str(), std::fstream::in); //filename?                                  
  parseJSONArray(artistImageStream);
  artistImageStream.close();

}

std::string ArtistImages::htmlString(){ 
  std::stringstream ssArtistImages;

  ssArtistImages << "\n";
  ssArtistImages << "<ol>\n>";
  
  for (std::vector<ArtistImage*>::iterator iter = listOfArtistImages()->begin(); iter !=listOfArtistImages()->end(); ++iter )
    ssArtistImages << (*iter)->htmlString();
  ssArtistImages << "\n</ol>";
}
  
void ArtistImages::runAsserts(){

}

