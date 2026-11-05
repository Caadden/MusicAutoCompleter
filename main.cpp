#include "song.h"
#include <vector>
#include <utility>
#include <fstream>
#include <chrono>

std::pair<std::vector<song*>, std::vector<artist*>> csvParse(std::string& fileName) {
    //declare vectors
    //open file
    //move to first song
    //parse song info & add to vector
    //check if duplicate artist
        //if no dupe, add to vector and add obj to song with ref to song in artist
        //if dupe, add existing obj to song with ref to song in artist
    //repeat until eof
    //close file
    //add both vectors to pair
    //return pair (pair stores by copy, so it should be ok to return!)
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
    //while loop, send all valid songs to trie and hash
    //while loop, send all valid artists to trie and hash

    //Main UI and Selection
    //while true loop, present selections and wait for input
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