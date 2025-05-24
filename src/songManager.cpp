#include "../include/SongManager.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Constructor for Song - sets name and author when song is created
Song::Song(const string& name, const string& author)
    : name(name), author(author) {}

// Get the name of the song
string Song::getName() const {
    return name;
}

// Get the name of the author
string Song::getAuthor() const {
    return author;
}

// Adds a new song to our playlist (stored in the memory first)
void SongManager::addSong(const string& name, const string& author) {
    Song newSong(name, author);
    playlist.push_back(newSong);  // now saving it in the vector
    cout << setw(10) << "" << "Added: " << name << " by " << author << "\n";
}

// Save all added songs to a CSV file like a spreadsheet
void SongManager::saveToCSV(const string& filename) const {
    ofstream outFile(filename, ios::app);  // open file in append mode
    if (outFile.is_open()) {
        if (outFile.tellp() == 0) {  // if file is empty, add header
            outFile << "Song Name,Author\n";
        }

        for (int i = 0; i < playlist.size(); i++) {
            outFile << playlist[i].getName() << "," << playlist[i].getAuthor() << "\n";
        }

        outFile.close();
        cout << setw(10) << "" << "Songs saved to CSV file.\n";
    } else {
        cout << setw(10) << "" << "Failed to open CSV file.\n";
    }
}

// Save songs to a binary file that stores each record as bytes
void SongManager::saveToBinary(const string& filename) const {
    ofstream binFile(filename, ios::binary | ios::app);  // open file in append mode
    if (binFile.is_open()) {
        for (int i = 0; i < playlist.size(); i++) {
            string name = playlist[i].getName();
            string author = playlist[i].getAuthor();

            int nameLen = name.length();
            int authorLen = author.length();

            // Write song name length and then the content
            binFile.write((char*)&nameLen, sizeof(int));
            binFile.write(name.data(), nameLen);  // write name content

            // Write author name length and then the content
            binFile.write((char*)&authorLen, sizeof(int));
            binFile.write(author.data(), authorLen);  // write author content
        }

        binFile.close();
        cout << setw(10) << "" << "Songs saved to binary file.\n";
    } else {
        cout << setw(10) << "" << "Failed to open binary file.\n";
    }
}

// Read songs back from the CSV and show them in terminal
void SongManager::displayFromCSV(const string& filename) const {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        string line;
        cout << setw(10) << "" << "--- Songs in CSV File ---\n";
        while (getline(inFile, line)) {
            cout << setw(10) << "" << line << "\n";
        }
        inFile.close();
    } else {
        cout << setw(10) << "" << "Unable to read from CSV file.\n";
    }
}

// Read songs back from binary and show them (reads simple strings and displays)
void SongManager::displayFromBinary(const string& filename) const {
    ifstream binFile(filename, ios::binary);
    if (binFile.is_open()) {
        cout << setw(10) << "" << "--- Songs in Binary File ---\n";

        while (!binFile.eof()) {
            int nameLen = 0;
            binFile.read((char*)&nameLen, sizeof(int));
            if (binFile.gcount() == 0) break;  // no more data

            string name(nameLen, ' ');
            binFile.read(&name[0], nameLen);  // Read song name

            int authorLen = 0;
            binFile.read((char*)&authorLen, sizeof(int));

            string author(authorLen, ' ');
            binFile.read(&author[0], authorLen);  // Read author

            cout << setw(10) << "" << name << " by " << author << "\n";
        }

        binFile.close();
    } else {
        cout << setw(10) << "" << "Unable to read from binary file.\n";
    }
}

// Complete flow - now asks user for songs and saves to both files
void SongManager::run() {
    char again = 'y';
    string name, author;

    while (tolower(again) == 'y') {
        cout << setw(10) << "" << "Enter song name: ";
        cin.ignore();  // clear any previous leftover newline
        getline(cin, name);

        cout << setw(10) << "" << "Enter author name: ";
        getline(cin, author);

        addSong(name, author);

        cout << setw(10) << "" << "Add another song? (y/n): ";
        cin >> again;
    }

    // Save to specific data folder with consistent naming
    saveToCSV("data/emergency_session.csv");
    saveToBinary("data/emergency_session.dat");

    // Show everything stored in files
    cout << "\n";
    displayFromCSV("data/emergency_session.csv");
    cout << "\n";
    displayFromBinary("data/emergency_session.dat");
}
