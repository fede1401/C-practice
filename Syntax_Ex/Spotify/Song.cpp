#include "Song.hpp"
#include <iostream>

// Costruttore di default
Song::Song() {}

// Costruttore parametrico
Song::Song(std::string title, std::string artist, float seconds, std::string genre, enum Vote vote, int yearPubl) {
    this->title = title;
    this->artist = artist;
    this->seconds = seconds;
    this->genre = genre;
    this->vote = vote;
    this->yearPubl = yearPubl;
}


// Getter
std::string Song::getTitle() { return title; }
std::string Song::getArtist() { return artist; }
float Song::getSeconds() { return seconds; }
std::string Song::getGenre() { return genre; }
enum Vote Song::getVote() { return vote; }
int Song::getYearPubl() { return yearPubl; }


// Setter
void Song::setTitle(std::string title) { this->title = title; }
void Song::setArtist(std::string artist) { this->artist = artist; }
void Song::setSeconds(float seconds) { this->seconds = seconds; }
void Song::setGenre(std::string genre) { this->genre = genre; }
void Song::setVote(enum Vote vote) { this->vote = vote; }
void Song::setYearPubl(int yearPubl) { this->yearPubl = yearPubl; }


// Metodo toString per stampare la canzone
void Song::toString() {
    std::cout << "Song Info" << std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Artist: " << artist << std::endl;
    std::cout << "Duration: " << seconds << " sec" << std::endl;
    std::cout << "Genre: " << genre << std::endl;
    std::cout << "Vote: " << (int)(vote) << "/5" << std::endl;
    std::cout << "Year: " << yearPubl << std::endl;
}
