#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <vector>
#include <iostream>
#include "Song.hpp"

class Playlist{

    private:
        std::string name;
        Song *songs;
        int songCount;


    public:
        Playlist();
        Playlist(std::string name, Song *songs, int songCount);
        ~Playlist();

        // Getter and Setter
        std::string getName();
        Song* getSongs();
        int getSoungCount();

        void setName(std::string name);
        void setSongs(Song* songs);
        void setSongCount(int songCount);
    
        // Other methods
        void addSong(Song newSong);
        void removeSong(std::string title);
        void removeSong(int index);
        void toString();
        float calcTotalSec();

        // Order
        Song* getSongOrderByTime();
        Song* getSongOrderByVal();

        // Filter
        Song* filterByGenre();
        Song* filterByArtist();
};

#endif