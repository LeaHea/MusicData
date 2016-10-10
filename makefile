all : Project3.x

# dependencies for Project3.x

Project3.x :  main.o Track.o Tracks.o Album.o Albums.o Artist.o Artists.o JSONDataItem.o JSONArray.o JSONDataObject.o AlbumImage.o AlbumImages.o ArtistImage.o ArtistImages.o
	g++ -std=c++11 -ggdb -o Project1.x main.o JSONDataItem.o JSONDataObject.o JSONArray.o Track.o Tracks.o Album.o Albums.o Artist.o Artists.o AlbumImage.o AlbumImages.o ArtistImage.o ArtistImages.o

main.o : main.cpp
	g++ -c main.cpp -g

JSONArray.o : JSONArray.hpp  JSONArray.cpp
	g++ -c  JSONArray.hpp JSONArray.cpp -g

JSONDataItem.o : JSONDataItem.hpp  JSONDataItem.cpp
	g++ -c  JSONDataItem.hpp JSONDataItem.cpp -g

JSONDataObject.o : JSONDataObject.hpp  JSONDataObject.cpp
	g++ -c  JSONDataObject.hpp JSONDataObject.cpp -g

Track.o : Track.hpp Track.cpp
	g++ -c  Track.cpp -g

Artist.o : Artist.hpp Artist.cpp
	g++ -c Artist.hpp Artist.cpp -g

Album.o : Album.hpp Album.cpp
	g++ -c Album.hpp Album.cpp -g

AlbumImage.o : AlbumImage.hpp AlbumImage.cpp
	g++ -c AlbumImage.hpp AlbumImage.cpp -g

ArtistImage.o : ArtistImage.hpp ArtistImage.cpp
	g++ -c ArtistImage.hpp ArtistImage.cpp -g

Tracks.o : Tracks.hpp Tracks.cpp
	g++ -c  Tracks.cpp -g

Artists.o : Artists.hpp Artists.cpp
	g++ -std=c++11 -c Artists.hpp Artists.cpp -g

Albums.o : Albums.hpp Albums.cpp
	g++ -c Albums.hpp Albums.cpp -g

AlbumImages.o : AlbumImages.hpp AlbumImages.cpp
	g++ -c AlbumImages.hpp AlbumImages.cpp -g

ArtistImages.o : ArtistImages.hpp ArtistImages.cpp
	g++ -c ArtistImages.hpp ArtistImages.cpp -g

clean:
	#cp tracks_template.html track.html
	#cp albums_template.html album.html
	#cp artists_template.html artists.html
	#cp artistImages_template.html artistImages.html
	#cp albumImages_template.html albumImages.html
	rm *o *# *gch *~ ~/cs315/Project3/Albums/*

