#ifndef _ALBUM
#define _ALBUM

//#include "JSONDataObject.hpp"
#include "AlbumImages.hpp"
#include "Tracks.hpp"                                                                                                              
   
class Album: public JSONDataObject {
public:
  Album();
  Album(JSONDataObject *json);
  ~Album();

  std::string title();
  std::string genre();  
  std::string year();  
  unsigned albumID();
  unsigned numTracks();
  unsigned numImages();
  unsigned artistID();  
  void print();
  std::string htmlString();

  bool hasTitle() { return title() != ""; }
  bool hasGenre() { return genre() != ""; }
  bool hasYear() { return year() != ""; }
  bool hasAlbumID() { return albumID() != 0; }
  bool hasNumTracks() { return numTracks() != 0; }
  bool hasArtistID() { return artistID() != 0; }
  bool hasNumImages() { return numImages() != 0; }

  void setTracks(Tracks *tracks) { _tracks = tracks; };

  Tracks *tracks()  { return _tracks; }
  AlbumImage *&primaryImage() { return _primaryImage;   }
  AlbumImage *&secondaryImage()  { return _secondaryImage; }

private:
  
  bool cachedTitle, cachedGenre, cachedYear, cachedAlbumID, cachedArtistID, cachedNumImages, cachedNumTracks;
  std::string _title, _genre, _year;
  unsigned _albumID, _artistID, _numTracks, _numVideos, _numImages;;
                                                                                                                                                                   
  AlbumImage *_primaryImage, *_secondaryImage;
   // Album *_albums;
  Tracks *_tracks;
};

#endif
