#include "JSONDataObject.hpp"
#include "ArtistImage.hpp"
#include "Albums.hpp"

class Artist: public JSONDataObject {
public:
  Artist();
  Artist(JSONDataObject *);
  ~Artist();

  std::string profile();
  std::string artistName();
  std::string realName();
  std::string numImages();
  unsigned artistID();

  bool hasProfile() { return profile() != ""; }
  bool hasArtistName() { return artistName() != ""; }
  bool hasRealName() { return realName() != ""; }
  bool hasImages() { return numImages() != ""; }
  bool hasArtistID() { return artistID() != 0; }

  void print();
  std::string htmlString();

  // the following 4 function-prototypes are new to this project.
  void setAlbums(Albums *albums) { _albums = albums; }
  Albums *albums() { return _albums; }
    
  ArtistImage *&primaryImage() { return _primaryImage; }
  ArtistImage *&secondaryImage() { return _secondaryImage; }

private:
  std::string _name, _numImages, _realName, _profile;
  unsigned _artistID;
  bool cachedName, cachedRealName, cachedProfile, cachedNumImages, cachedArtistID;

  ArtistImage *_primaryImage, *_secondaryImage;
  Albums *_albums;
};
