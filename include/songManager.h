//
// Created by Subigya Parajuli on 5/2/25.
//

#ifndef SONG_MANAGER_H
#define SONG_MANAGER_H

#include <string>
#include <vector>
using namespace std;

// Handling one song - author and the song title
// Demonstrates encapsulation through private data members
class Song {
private:
    string name; // name of the song
    string author;

public:
    Song() = default; // default constructor
    Song(const string& name, const string& author); // parameeters

    // grabbing song info
    string getName() const;
    string getAuthor() const;
};

//another class added for managing songs
class SongManager {
private:
    vector<Song> playlist; // Stores all songs added by the user

public:
    // Adds a new song to the playlist
    void addSong(const string& name, const string& author);

    // Save all songs to a text-based CSV file
    void saveToCSV(const string& filename) const;

    // Save all songs to a binary .dat file
    void saveToBinary(const string& filename) const;

    // Load and display all songs from a CSV file
    void displayFromCSV(const string& filename) const;

    // Load and display all songs from a binary file
    void displayFromBinary(const string& filename) const;

    void run(); // user flow based
};

#endif
