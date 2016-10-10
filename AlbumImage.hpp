#ifndef _ALBUMIMAGE
#define _ALBUMIMAGE

#include "JSONDataObject.hpp"

class AlbumImage: public JSONDataObject {
  public:
  AlbumImage();
  AlbumImage(JSONDataObject *);
  ~AlbumImage();
  
  std::string type();
  std::string uri();
  unsigned albumID();
  unsigned width();
  unsigned height();
  
  bool hasType() { return type() != ""; }
  bool hasUri() { return uri() != ""; }
  bool hasAlbumID() { return albumID() != 0; }
  bool hasWidth() { return width() != 0; }
  bool hasHeight() { return height() != 0; }

  bool isPrimary() { if (type() == "primary") return true; }
  bool isSecondary() { if (type() == "secondary") return true; }
  
  AlbumImage *primaryImage(){ return _primaryImage; };
  AlbumImage *secondaryImage(){ return _secondaryImage; };

  virtual void print();
  std::string htmlString();
     
private:
  std::string _type, _uri;
  unsigned _width, _albumID, _height;
  bool cachedType, cachedAlbumID, cachedUri, cachedWidth, cachedHeight;  

  AlbumImage *_albumImage, *_primaryImage, *_secondaryImage;

};

#endif
