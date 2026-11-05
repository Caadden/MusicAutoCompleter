#include "artist.h"

artist::artist(std::string inputArtistName) {
    artistName = inputArtistName;
}

std::string artist::getArtistName() {
    return artistName;
}

std::vector<song*> artist::getSongList() {
    return songList;
}

void artist::addSong(song* songToAdd) {
    songList.push_back(songToAdd);
}
