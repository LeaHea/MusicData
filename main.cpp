// Leah Headd
// Project 3
// 4/6/2015

#include <fstream>
#include <cstring>
#include <vector>
#include "JSONArray.hpp"

#include "Artists.hpp"

int main()
{
 
  Artists *_artist = new Artists;  
  _artist->loadArtistsFromFile("artists.json");    
  Tracks *_track = new Tracks;
  _track->loadTracksFromFile("tracks.json");    
  Albums *_album = new Albums;
  _album->loadAlbumsFromFile("albums.json");    
  
  ArtistImages *_artistImages = new ArtistImages;
  _artistImages->loadArtistImagesFromFile("artistImages.json");    
  AlbumImages *_albumImages = new AlbumImages;
  _albumImages->loadAlbumImagesFromFile("albumImages.json");    
 
 
  _album->setTracksForAlbums(_track);
  _album->setImagesForAlbums(_albumImages);

  _artist->setImagesForArtists(_artistImages);
  _artist->setAlbumsForArtists(_album);  
  _artist->htmlString(); 
 
  std::cout << "done!\n";
 
  return 1;

}

 
