#ifndef _ALBUMS
#define _ALBUMS

#include "Album.hpp"

class Albums: public JSONArray
{
public:
  Albums(){}
  ~Albums();
  
  int numAlbums();
  void addAlbum(Album *album);
  Album* albumWithID(unsigned int alID);
  void loadAlbumsFromFile(std::string fileName);
  std::string htmlString();
  virtual JSONDataObject *jsonObjectNode() { return new Album(); }
  
  void setTracksForAlbums( Tracks * );
  void setImagesForAlbums( AlbumImages * );

  std::vector<Album *> *listOfAlbums() { return (std::vector<Album *> *) _listOfDataObjects; };
  void runAsserts();  // used for checking the integrity of this class.
};

#endif
