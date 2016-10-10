#include "Tracks.hpp"

Tracks::~Tracks(){
  
}

int Tracks::numTracks(){
  return _listOfDataObjects->size();
}

void Tracks::addTrack(Track *track){
  _listOfDataObjects->push_back(track);
}

void Tracks::loadTracksFromFile(std::string fileName){
  std::fstream trackStream;
  trackStream.open(fileName.c_str(), std::fstream::in); //filename?
  parseJSONArray(trackStream);
  trackStream.close();
}

std::string Tracks::htmlString(){
    std::stringstream ssTracks;

      ssTracks << "\n";
      ssTracks << "<ol>\n";
      for (std::vector<Track*>::iterator iter = listOfTracks()->begin(); iter !=listOfTracks()->end(); ++iter ){
	ssTracks << (*iter)->htmlString();}
      ssTracks << "\n</ol>";
            
      return ssTracks.str();
}

void Tracks::runAsserts(){

}
