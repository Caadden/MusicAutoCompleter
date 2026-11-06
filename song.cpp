#include "song.h"
#include "artist.h"

song::song(std::string inputTrackID, std::string inputAlbum, std::string inputTrackName, unsigned int inputPopularity,
    unsigned int inputDuration, bool inputIsExplicit, float inputDanceability, float inputEnergy, int inputKey,
    float inputLoudness, bool inputMode, float inputSpeechiness, float inputAcousticness, float inputInstrumentalness,
    float inputLiveness, float inputValence, int inputTempo, int inputBeatsPerBar, std::string inputGenre) {
    trackID = inputTrackID;
    album = inputAlbum;
    trackName = inputTrackName;
    popularity = inputPopularity;
    duration = inputDuration;
    isExplicit = inputIsExplicit;
    danceability = inputDanceability;
    energy = inputEnergy;
    key = inputKey;
    loudness = inputLoudness;
    mode = inputMode;
    speechiness = inputSpeechiness;
    acousticness = inputAcousticness;
    instrumentalness = inputInstrumentalness;
    liveness = inputLiveness;
    valence = inputValence;
    tempo = inputTempo;
    beatsPerBar = inputBeatsPerBar;
    genre = inputGenre;
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

float song::getDanceability() {
    return danceability;
}

float song::getEnergy() {
    return energy;
}

std::string song::getKey() {
    if (key == 0) {return "C";}
    if (key == 1) {return "C#/D♭";}
    if (key == 2) {return "D";}
    if (key == 3) {return "D#/E♭";}
    if (key == 4) {return "E";}
    if (key == 5) {return "F";}
    if (key == 6) {return "F#/G♭";}
    if (key == 7) {return "G";}
    if (key == 8) {return "G#/A♭";}
    if (key == 9) {return "A";}
    if (key == 10) {return "A#/B♭";}
    if (key == 11) {return "B";}
    return "Unknown";
}

float song::getLoudness() {
    return loudness;
}

float song::getSpeechiness() {
    return speechiness;
}

float song::getAcousticness() {
    return acousticness;
}

float song::getValence() {
    return valence;
}

int song::getTempo() {
    return tempo;
}

int song::getBeatsPerBar() {
    return beatsPerBar;
}

std::string song::getGenre() {
    return genre;
}

void song::setArtist(artist* inputTrackArtist) {
    trackArtist = inputTrackArtist;
}
