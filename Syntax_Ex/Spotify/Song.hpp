#ifndef SONG_H
#define SONG_H

#include <string>

enum Vote{
    ONE = 1,
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5
};

class Song{

    private:
        std::string title;
        std::string artist;
        float seconds;
        std::string genre;
        enum Vote vote;
        int yearPubl;

    public:
        Song();
        Song(std::string title, std::string artist, float second, std::string genre, enum Vote vote, int yearPubl);


        // Getter
        std::string getTitle();
        std::string getArtist();
        float getSeconds();
        std::string getGenre();
        enum Vote getVote();
        int getYearPubl();

        // Setter
        void setTitle(std::string title);
        void setArtist(std::string artist);
        void setSeconds(float seconds);
        void setGenre(std::string genre);
        void setVote(enum Vote vote);
        void setYearPubl(int yearPubl);


        void toString();
};

#endif