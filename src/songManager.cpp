/*#include <iostream>     // for input/output
#include <fstream>      // for file operations
#include <iomanip>      // for formatting (setw, setfill)
#include <cstring>      // for C-style strings

using namespace std;

// Creating a namespace for file manager
namespace fileManager {

    // Struct used to match binary structure written from calorieChecker
    struct BinarySession {
        char workout[30];
        double weight;
        double duration;
        double calories;
    };

    // Reads emergency session data from the binary file and prints it
    void readEmergencySessionsFromBinary() {
        // Use the correct absolute path to match where the file is written
        ifstream inFile("/Users/subigyaparajuli/Desktop/FitnessTrackerV3/data/emergency_session.dat", ios::binary);

        if (!inFile.is_open()) {
            cerr << "Error: Could not open binary file at expected path.\n";
            return;
        }

        BinarySession s;
        int count = 1;

        cout << setfill('=') << setw(40) << "=" << endl;
        cout << "     Emergency Session Binary Log\n";
        cout << setfill('=') << setw(40) << "=" << endl;

        // Read and print each session until end-of-file
        while (inFile.read(reinterpret_cast<char*>(&s), sizeof(BinarySession))) {
            cout << "Session #" << count++ << ":\n";
            cout << "  Workout:  " << s.workout << "\n";
            cout << "  Weight:   " << s.weight << " kg\n";
            cout << "  Duration: " << s.duration << " min\n";
            cout << "  Calories: " << s.calories << " KCal\n";
            cout << setfill('-') << setw(30) << "-" << endl;
        }

        inFile.close();
    }

}
*/