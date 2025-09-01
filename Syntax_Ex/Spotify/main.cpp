#include "Playlist.hpp"
#include "Song.hpp"

int main(){
    Song s1 = Song("The Hills", "The Weeknd", 242, "Pop", Vote::FOUR, 2022);
    Song s2 = Song("Start Again", "One Repulic x Vegas jones", 201, "Pop x Rap", Vote::FOUR, 2018);
    Song s3 = Song("Stop and Share", "One Repulic", 200, "Pop", Vote::FIVE, 2020);

    Song songs[3] = {s1, s2, s3};
    Playlist playlist = Playlist("Federico's playlist", &songs[0], 3);
    //playlist.toString();

    playlist.addSong(Song("SCELTE STUPIDE", "Fedez & Clara", 250, "Rap", Vote::THREE, 2025));
    //playlist.toString();

    /*playlist.removeSong("Start Again");
    playlist.toString();

    playlist.removeSong(1);
    playlist.toString();*/

    Song *orderSong = playlist.getSongOrderByTime();
    playlist.setSongs(orderSong);
    playlist.toString();
    delete[] orderSong;


    //std::cout << "Secondi totali: " <<  playlist.calcTotalSec() << std::endl;

}