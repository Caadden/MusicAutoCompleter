#pragma once

#include "song.h"
#include <string>
#include <vector>

class artist {
    std::string artistName;
    std::vector<song*> songList;
    //we can derive more data from the csv about each artist and store it here later if we wish to

public:
    artist(std::string inputArtistName);
    //getters
    std::string getArtistName();
    std::vector<song*> getSongList();
    //explicit setters are not necessary, artist name and song list should not be set to entirely new values at any time
    //other
    void addSong(song* songToAdd);
};