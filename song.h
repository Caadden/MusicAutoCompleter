#pragma once

#include "artist.h"
#include <string>

class song {
    std::string trackID;
    artist* trackArtist = nullptr;
    std::string album;
    std::string trackName;
    unsigned int popularity;
    unsigned int duration;
    bool isExplicit;
    unsigned int danceability;

public:
    song(std::string inputTrackID, std::string inputAlbum, std::string inputTrackName, unsigned int inputPopularity,
         unsigned int inputDuration, bool inputIsExplicit, unsigned int inputDanceability);
    //getters
    std::string getTrackID();
    artist* getArtist();
    std::string getAlbum();
    std::string getTrackName();
    unsigned int getPopularity();
    unsigned int getDuration();
    bool getExplicit();
    unsigned int getDanceability();
    //setters
    void setArtist(artist* inputTrackArtist);
    //all other vars should be set at declaration and do not need to be changed afterward
};