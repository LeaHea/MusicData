#include "JSONDataObject.hpp"
                                                                                                                                           
class Track: public JSONDataObject {
public:

  Track();
  Track(JSONDataObject *);
  ~Track();

  std::string title();
  std::string artistName();
  std::string albumName();  
  std::string duration();  
  std::string position();
  unsigned albumID();  

  virtual void print();
  std::string htmlString();
 
  bool hasTitle() { return title() != ""; }
  bool hasArtistName() { return artistName() != ""; }
  bool hasAlbumName() { return albumName() != ""; }
  bool hasDuration() { return duration() != ""; }
  bool hasPosition() { return position() != ""; }
  bool hasAlbumID() { return albumID() != 0; }
  

private:
  
  bool cachedArtistName, cachedTitle, cachedAlbumName, cachedDuration, cachedPosition, cachedAlbumID;
  std::string _artistName, _title, _albumName, _duration, _position;
  unsigned _albumID;

};





  


