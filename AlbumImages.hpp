#ifndef _ALBUMIMAGES
#define _ALBUMIMAGES

#include "JSONArray.hpp"
#include "AlbumImage.hpp"

class AlbumImages: public JSONArray
{
public:
  AlbumImages(){}
  ~AlbumImages();
  
  int numAlbumImages();
  void addAlbumImage(AlbumImage *albumImage);
  AlbumImage *albumImageWithID(unsigned int tID);
  void loadAlbumImagesFromFile(std::string fileName);
  std::string htmlString();
  virtual JSONDataObject *jsonObjectNode() { return new AlbumImage(); }
  
  std::vector<AlbumImage *> *listOfAlbumImages() { return (std::vector<AlbumImage *> *) _listOfDataObjects; }
  void runAsserts();  // used for checking the integrity of this class.

};

#endif
