#include "song.h"
//#include "trie.h"
//#include "HashTable.h"
#include <vector>
#include <utility>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <iostream>
#include <chrono>


std::pair<std::vector<song*>, std::vector<artist*>> csvParse(const std::string& fileName) {
    //declare variables n such
    std::unordered_map<std::string, artist*> artistMap; //unordered map used for looking for dupe artists
    std::vector<song*> songList;
    std::vector<artist*> artistList;
    //open file
    std::ifstream trackDataset (fileName);
    if (trackDataset.is_open()) {
        std::string songData;
        std::getline(trackDataset, songData); //removes data labels
        std::vector<std::string> songTokenized; //since all tokens need to be accessed at once, all get held in vector
        std::string temp; //holds string to be added to vector
        while (std::getline(trackDataset, songData)) { //loop through each line (song)
            std::stringstream songStream(songData); //data to stream so it's usable with getline
            while (songStream.peek() != std::istream::traits_type::eof()) {
                if (songStream.peek() == '\"') {
                    int quoteCount = 1;
                    songStream.ignore();
                    songTokenized.emplace_back("");
                    while (std::getline(songStream, temp, '\"')) {
                        songTokenized.back() += temp;
                        if (songStream.peek() == ',') {
                            if (temp.empty() == true || temp.substr(temp.size() - 1, 1) != " ") {
                                songStream.ignore();
                                if (songStream.peek() != ' ' && quoteCount % 2 == 1) {
                                    break;
                                }
                                songTokenized.back() += "\",";
                                quoteCount++;
                                continue;
                            }
                        }
                        songTokenized.back() += "\"";
                        quoteCount++;
                    }
                }
                else {
                    std::getline(songStream, temp, ',');
                    songTokenized.push_back(temp);
                }
            }
            songList.push_back(new song(songTokenized.at(2), songTokenized.at(4), songTokenized.at(5),
                                        std::stoul(songTokenized.at(6)), std::stoul(songTokenized.at(7)),
                                        songTokenized.at(8) == "True", std::stof(songTokenized.at(9)) * 100,
                                        std::stof(songTokenized.at(10)) * 100, std::stoi(songTokenized.at(11)),
                                        std::stof(songTokenized.at(12)), std::stoi(songTokenized.at(13)),
                                        std::stof(songTokenized.at(14)) * 100, std::stof(songTokenized.at(15)) * 100,
                                        std::stof(songTokenized.at(16)) * 100, std::stof(songTokenized.at(17)) * 100,
                                        std::stof(songTokenized.at(18)) * 100, std::stoi(songTokenized.at(19)),
                                        std::stoi(songTokenized.at(20)), songTokenized.at(21)));
            //verify artist, only the first artist mentioned is used
            if (songTokenized.at(3).find(';') != std::string::npos) {
                songTokenized.at(3) = songTokenized.at(3).substr(0,songTokenized.at(3).find(';'));
            }

            artist* currentArtist = nullptr;
            auto it = artistMap.find(songTokenized.at(3));

            //checks if artist is already present
            if (it == artistMap.end()) {
                currentArtist = new artist(songTokenized.at(3));
                artistMap[songTokenized.at(3)] = currentArtist;
                artistList.push_back(currentArtist);
            }
            else {
                currentArtist = it->second;
            }

            currentArtist->addSong(songList.back());
            songList.back()->setArtist(currentArtist);

            //std::cout << "song #" << songTokenized.at(0) << " added!\n"; //FOR DEBUG ONLY, COMMENT OUT LATER

            songTokenized.clear();
        }
        trackDataset.close();
    }
    else {
        throw std::ios_base::failure("Unable to open \"" + fileName + "\", ensure the file is correctly placed and restart the program.");
    }

    return std::make_pair(songList, artistList);
}

int main() {
    /*
     *TODO:
     * - Parse inputs, then add results to tries & hashes
     * - Initial selection menu
     * - Song name search (with select between hash and trie search methods)
     * - Artist name search (with select between hash and trie search methods)
     * - More details when selecting a song/artist after search
     * - Time execution comparison
     */

    //Layout


    //Setup
    //send filename to csvParse, get back pair with all valid songs and artists
    auto parsedData = csvParse("..\\spotify-tracks-dataset.csv");


    // trie songTrie();
    // trie artistTrie();
    // HashTable songHash();
    // HashTable artistHash();
    bool structureType;
    char menuInput;

    // //loop, send all valid songs to trie and hash
    // for (song* i : parsedData.first) {
    //     songTrie.insert(i->getTrackName(), i);
    //     songHash.insert(i->getTrackName(), i);
    // }
    // //loop, send all valid artists to trie and hash
    // for (artist* i : parsedData.second) {
    //     artistTrie.insert(i->getArtistName(), i);
    //     artistHash().insert(i->getArtistName(), i);
    // }

    //Main UI and Selection
    //while true loop, present selections and wait for input
    std::cout << "**************************************************************************\n";
    std::cout << "*                                                                        *\n";
    std::cout << "*                                                                        *\n";
    std::cout << "*                       Music Search Autocompleter                       *\n";
    std::cout << "*                                                                        *\n";
    std::cout << "*                                                                        *\n";
    std::cout << "**************************************************************************\n\n\n";
    std::cout << "Welcome to the Music Search Autocompleter, a program that aims to process\n";
    std::cout << "and serve information regarding the top songs on Spotify! To begin, please\n";
    std::cout << "select which data structure you'd like to use (this can be changed later).\n\n";
    std::cout << "             1:Trie                    0:Hash                             \n\n";
    std::cin >> structureType;
    std::cout << "\n\n                               Main Menu:\n";
    std::cout << "                     (Use Number Keys to Navigate)\n\n";
    std::cout << "1. Search by Song Name (e.g, \"Smooth Criminal\")\n";
    std::cout << "2. Search by Artist Name (e.g, \"Michael Jackson\")\n";
    std::cout << "3. Swap Preferred Data Structure (Hash/Trie)\n";
    std::cout << "4. Time Execution Comparison\n";
    std::cout << "5. Quit\n\n";
    while (true) {
        std::cin >> menuInput;
        if (menuInput == '1') {
            std::cout << "WIP_SONG_NAME_SEARCH\n";
        }
        else if (menuInput == '2') {
            std::cout << "WIP_ARTIST_NAME_SEARCH\n";
        }
        else if (menuInput == '3') {
            structureType = !structureType;
            std::cout << "Data structure switched successfully, you are now using the ";
            if (structureType) {std::cout << "trie!\n";} else {std::cout << "hash!\n";}
        }
        else if (menuInput == '4') {
            std::cout << "WIP_STRUCTURE_TIME_COMPARISON\n";
        }
        else if (menuInput == '5') {
            std::cout << "Thanks for using the Music Search Autocompleter, have a great day!";
            return 0;
        }
        else {
            std::cout << "Unrecognized menu selection, please try again.\n";
        }
    }


    //1. Search by Song Name
        //ask if trie search or hash search, or present both searches possibly?
        //perform search on selected type, max 5 prolly
        //Select 1-5 to pick a song, or 0 to return to menu
            //when song selected, display info about song (danceability, popularity, explicit, etc)
            //this menu should allow for picking another song from previous menu
    //2. Search by Artist Name
        //ask if trie search or hash search, or present both searches possibly?
        //perform search on selected type, max 5 prolly
        //Select 1-5 to pick an artist, or 0 to return to menu
            //when artist selected, display artist song list and allow user to pick a song to learn more (1-5)
                //when song selected, display info about song (danceability, popularity, explicit, etc)
                //this menu should allow for picking another song from previous menu
            //this menu should allow for picking another artist from previous menu
    //3. Time Execution Comparison
        //ask user if wishes to compare with artist or song data types
        //ask user for query to search for
        //start timer for hash and search. After found, stop timer
        //start timer for trie and search. After found, stop timer
        //Display time taken for both methods, differential between the two, and mark the faster data structure
    //4. Quit
        //break while loop
}