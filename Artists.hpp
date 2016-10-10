#ifndef _ARTISTS
#define _ARTISTS

#include "Artist.hpp"
#include "Albums.hpp"
#include "ArtistImages.hpp"

class Artists: public JSONArray
{
public:
  Artists(){}
  ~Artists();
  
  int numArtists();
  void addArtist(Artist *artist);
  Artist *artistWithID(unsigned int aID);
  void loadArtistsFromFile(std::string fileName);
  std::string htmlString();
  JSONDataObject *jsonObjectNode() { return new Artist();  }
  void setAlbumsForArtists(Albums *albums);
  void setImagesForArtists(ArtistImages *);
  std::vector<Artist *> *listOfArtists() { return (std::vector<Artist *> *) _listOfDataObjects; };
  void runAsserts();  // used for checking the integrity of this class.
};

#endif
