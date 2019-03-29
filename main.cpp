#include <iostream>
#include <fstream>
#include <iomanip>
#include "Surveillance.hpp"

using namespace std;

void readInputFile(Surveillance &history){
    // open the file
    ifstream inputFile("../peoplePlaces.txt");

    // variables for storing count and the current number
    string currentLine;
    string word;
    string person;
    vector<string> locations;

    // Store positions
    streampos inital = inputFile.tellg();
    streampos final;

    // determine size of the paired list
    while(getline(inputFile, currentLine)){
        // Record your new ending position
        final = inputFile.tellg();

        // Return to the begining of the line
        inputFile.seekg(inital);

        // The first word is the person
        inputFile >> person;

        // Grab words one at a time until the ending position has been reached
        while(final - inputFile.tellg() != 2){
            inputFile >> word;
            locations.push_back(word);
        }

        // Add to history
        history.addPersonToHistory(person, locations);

        // Clear the locations
        locations.clear();

        // Consume the /r or /n character
        getline(inputFile, currentLine);

        // Record your new starting position
        inital = inputFile.tellg();
    }

    // clear the buffer and close the file stream
    inputFile.clear();
    inputFile.close();
}

void checkLocation1(Surveillance& history){
    cout << "Visited both Krusty-Burger and Tavern" << endl;

    list<string> locations1;
    locations1.emplace_back("Krusty-Burger");
    locations1.emplace_back("Tavern");

    for(auto it=history.getVisitHistory().begin(); it != history.getVisitHistory().end(); ++it){
        if(history.locationVisted(it->first, locations1)){
            cout << it->first << endl;
        }
    }

    cout << endl;
}

void checkLocation2(Surveillance& history){
    cout << "Did NOT visit Krusty-Burger and did NOT visit Home" << endl;

    list<string> locations1;
    locations1.emplace_back("Krusty-Burger");
    locations1.emplace_back("Home");

    for(auto it=history.getVisitHistory().begin(); it != history.getVisitHistory().end(); ++it){
        if(history.locationNotVisted(it->first, locations1)){
            cout << it->first << endl;
        }
    }

    cout << endl;
}

void checkLocation3(Surveillance& history){
    cout << "Visited Krusty-Burger and School but did NOT visit Tavern and NOT visit Home" << endl;

    list<string> locations1;
    locations1.emplace_back("Krusty-Burger");
    locations1.emplace_back("School");

    list<string> locations2;
    locations2.emplace_back("Tavern");
    locations2.emplace_back("Home");

    for(auto it=history.getVisitHistory().begin(); it != history.getVisitHistory().end(); ++it){
        if(history.locationVisted(it->first, locations1) && history.locationNotVisted(it->first, locations2)){
            cout << it->first << endl;
        }
    }

    cout << endl;
}

int main() {
    Surveillance history;
    readInputFile(history);

    // Print all in city
    cout << history;

    // Visited both Krusty-Burger and Tavern
    checkLocation1(history);

    // Did NOT visit Krusty-Burger and did NOT visit Home
    checkLocation2(history);

    // Visited Krusty-Burger and School but did NOT visit Tavern and NOT visit Home
    checkLocation3(history);

    // Visited everywhere and remove them
    history.findRegularPeople();

    return 0;
}