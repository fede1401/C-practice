#include "Playlist.hpp"

Playlist::Playlist(){};

Playlist::Playlist(std::string name, Song *songs, int songCount){
    this->name = name;
    this->songCount = songCount;
    this->songs = new Song[songCount] ;
    
    for (int i = 0; i<songCount; i++){
        this->songs[i] = songs[i];
        //std::cout << this->songs[i].getTitle() << std::endl;
    }
};

Playlist::~Playlist(){ delete songs; }



std::string Playlist::getName(){ return name; }

Song* Playlist::getSongs(){ return songs; }

int Playlist::getSoungCount(){ return songCount; }

void Playlist::setName(std::string name){ this->name = name; }

void Playlist::setSongs(Song* songs){ this->songs = songs; }

void Playlist::setSongCount(int songCount){ this->songCount = songCount;}

void Playlist::addSong(Song newSong){
    Song* newSongs = new Song[songCount + 1];
    for (int i = 0; i < songCount; i++) {
        newSongs[i] = songs[i];
    }
    newSongs[songCount] = newSong;
    delete[] songs;  // CORRETTO!
    songs = newSongs;
    songCount++;
    return;
}

void Playlist::removeSong(std::string title){
    for (int i = 0; i<songCount; i++){
        if (songs[i].getTitle() == title){
            for (int j = i; j<songCount-1; j++){
                songs[j] = songs[j+1];
            }
            songCount-=1;
            break;
        }
    }
    return;
}

void Playlist::removeSong(int index){
    for (int i = 0; i<songCount; i++){
        if (i == index){
            for (int j = i; j<songCount-1; j++){
                songs[j] = songs[j+1];
            }
            songCount-=1;
            break;
        }
    }
    return;
}

void Playlist::toString(){
    std::cout << "Playlist name: " << name << " with " << songCount << " song!" << std::endl;

    for (int i = 0; i<songCount; i++){
        Song s = this->songs[i];
        std::cout << "Song: " << s.getTitle() << ", artist: " 
        << s.getArtist() << ", duration in seconds: " << s.getSeconds() 
        << ", genre: " << s.getGenre() << ", with votation: " << s.getVote()
        << ", published in " << s.getYearPubl() << "\n\n";
    }

    std::cout << "\n\n";

    return;
}


float Playlist::calcTotalSec(){
    float res= 0;
    for (int i = 0; i<songCount; i++){ res += songs[i].getSeconds(); }
    return res;
}

int getShorterSong(std::vector<Song>& songs, int n) {
    if (songs.empty()) return -1;  // sicurezza

    int minIndex = 0;
    float minSec = songs[0].getSeconds();
    for (int i = 1; i < n; ++i) {
        if (songs[i].getSeconds() < minSec) {
            minSec = songs[i].getSeconds();
            minIndex = i;
        }
    }
    return minIndex;
}




Song* Playlist::getSongOrderByTime(){
    Song *songOrder = new Song[songCount];
    std::vector<Song> songgs;

    //Playlist playCopy = Playlist("Federico's playlist", &songs[0], 4);
    for (int i = 0; i<songCount; i++){ songgs.push_back(this->songs[i]); }
    //playCopy.toString();
    int j = 0;
    while (!songgs.empty()) {
        int shorterInt = getShorterSong(songgs, songgs.size());
        if (shorterInt < 0 || shorterInt >= songgs.size()) break;
        Song shorter = songgs[shorterInt];  
        songOrder[j] = shorter;
        j++;

        songgs.erase(songgs.begin() + shorterInt);
    }
    return songOrder;
}


Song* Playlist::getSongOrderByVal(){
    //std::vector<Song> songsVect;
    
}

Song* Playlist::filterByGenre(){}

Song* Playlist::filterByArtist(){}

