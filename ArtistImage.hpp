#ifndef _ARTISTIMAGE
#define _ARTISTIMAGE

#include "JSONDataObject.hpp"

class ArtistImage: public JSONDataObject {
public:
  ArtistImage();
  ArtistImage(JSONDataObject *);
  ~ArtistImage();
  
  std::string type();
  std::string uri();
  unsigned artistID();
  unsigned width();
  unsigned height();


  bool hasType() { return type() != ""; }
  bool hasUri() { return uri() != ""; }
  bool hasArtistID() { return artistID() != 0; }
  bool hasWidth() { return width() != 0; }
  bool hasHeight() { return height() != 0; }
  
  virtual void print();
  std::string htmlString();

  ArtistImage primaryImage() { return _primaryImage; }
  ArtistImage secondaryImage() { return _secondaryImage; }

private:
  std::string _type, _uri;
  unsigned _width, _artistID, _height;
  bool cachedType, cachedUri, cachedArtistID, cachedWidth, cachedHeight;
  

  ArtistImage *_primaryImage, *_secondaryImage;
  ArtistImage *_artistImage;
};


#endif
