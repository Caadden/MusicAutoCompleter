#pragma once

#include "artist.h"
#include <string>

class artist;

class song { //It is not necessary to show all details for every song, but all information given by the dataset about a song is stored here
    std::string trackID;
    artist* trackArtist = nullptr;
    std::string album;
    std::string trackName;
    unsigned int popularity;
    unsigned int duration; //in ms
    bool isExplicit;
    float danceability;
    float energy;
    int key;  //NOTE: key is stored as int, but should be returned as equivalent string when getter is called
    float loudness; //in dB
    bool mode;
    float speechiness;
    float acousticness;
    float instrumentalness;
    float liveness;
    float valence;
    int tempo;
    int beatsPerBar;
    std::string genre;

public:
    song(std::string inputTrackID, std::string inputAlbum, std::string inputTrackName, unsigned int inputPopularity,
         unsigned int inputDuration, bool inputIsExplicit, float inputDanceability, float inputEnergy,
         int inputKey, float inputLoudness, bool inputMode, float inputSpeechiness, float inputAcousticness,
         float inputInstrumentalness, float inputLiveness, float inputValence, int inputTempo, int inputBeatsPerBar,
         std::string inputGenre);
    //getters
    std::string getTrackID();
    artist* getArtist();
    std::string getAlbum();
    std::string getTrackName();
    unsigned int getPopularity();
    unsigned int getDuration();
    bool getExplicit();
    float getDanceability();
    float getEnergy();
    std::string getKey();
    float getLoudness();
    float getSpeechiness();
    float getAcousticness();
    float getValence();
    int getTempo();
    int getBeatsPerBar();
    std::string getGenre();
    //setters
    void setArtist(artist* inputTrackArtist);
    //all other vars should be set at declaration and do not need to be changed afterward
};