#ifndef _TRACKS
#define _TRACKS

#include "JSONArray.hpp"
#include "Track.hpp"

class Tracks: public JSONArray
{
public:
  Tracks(){};
  ~Tracks();
  
  int numTracks();
  void addTrack(Track *track);
  Track *trackWithID(unsigned int tID);
  void loadTracksFromFile(std::string fileName);
  std::string htmlString();
  virtual JSONDataObject *jsonObjectNode() { return new Track(); }
  
  std::vector<Track *> *listOfTracks() { return (std::vector<Track *> *) _listOfDataObjects; };
  void runAsserts();  // used for checking the integrity of this class.

};


#endif
