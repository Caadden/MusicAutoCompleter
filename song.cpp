#include "song.h"

song::song(std::string inputTrackID, std::string inputAlbum, std::string inputTrackName, unsigned int inputPopularity,
    unsigned int inputDuration, bool inputIsExplicit, unsigned int inputDanceability) {
    trackID = inputTrackID;
    album = inputAlbum;
    trackName = inputTrackName;
    popularity = inputPopularity;
    duration = inputDuration;
    isExplicit = inputIsExplicit;
    danceability = inputDanceability;
}

std::string song::getTrackID() {
    return trackID;
}

artist* song::getArtist() {
    return trackArtist;
}

std::string song::getAlbum() {
    return album;
}

std::string song::getTrackName() {
    return trackName;
}

unsigned int song::getPopularity() {
    return popularity;
}

unsigned int song::getDuration() {
    return duration;
}

bool song::getExplicit() {
    return isExplicit;
}

unsigned int song::getDanceability() {
    return danceability;
}

void song::setArtist(artist* inputTrackArtist) {
    trackArtist = inputTrackArtist;
}
