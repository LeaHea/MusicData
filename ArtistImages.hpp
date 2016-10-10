#include "JSONArray.hpp"
#include "ArtistImage.hpp"

class ArtistImages: public JSONArray
{
public:
  ArtistImages(){};
  ~ArtistImages();
  
  int numArtistImages();
  void addArtistImage(ArtistImage *artistImage);
  ArtistImage *artistImageWithID(unsigned int tID);
  void loadArtistImagesFromFile(std::string fileName);
  std::string htmlString();
  virtual JSONDataObject *jsonObjectNode() { return new ArtistImage(); }
  
  std::vector<ArtistImage *> *listOfArtistImages() { return (std::vector<ArtistImage *> *)  _listOfDataObjects; };
  void runAsserts();  // used for checking the integrity of this class.

};
