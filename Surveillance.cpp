//
// Created by AL on 2019-03-29.
//

#include <algorithm>
#include <iostream>
#include <list>
#include "Surveillance.hpp"


void Surveillance::addPersonToHistory(std::string person, const std::vector<std::string> &locations){
    visitHistory.insert(std::pair<std::string, std::vector<std::string>>(person, locations));
}

bool Surveillance::locationVisted(std::string person, std::list<std::string> locations){
    for(auto it = locations.begin(); it != locations.end(); ++it){
        auto it2 = find (visitHistory[person].begin(), visitHistory[person].end(), *it);
        if (it2 == visitHistory[person].end()){
            return false;
        }
    }

    return true;
}

bool Surveillance::locationNotVisted(std::string person, std::list<std::string> locations){
    for(auto it = locations.begin(); it != locations.end(); ++it){
        auto it2 = find (visitHistory[person].begin(), visitHistory[person].end(), *it);
        if (it2 != visitHistory[person].end()){
            return false;
        }
    }

    return true;
}


void Surveillance::findRegularPeople(){
    long max = 0;
    std::list<std::string> removeList;

    for(auto it = visitHistory.begin(); it != visitHistory.end(); ++it){
        if(it->second.size() > max){
            max = it->second.size();
        }
    }

    std::cout << "Removing visited all locations." << std::endl;

    for(auto it = visitHistory.begin(); it != visitHistory.end(); ++it){
        if(it->second.size() == max){
            std::cout << it->first << std::endl;
            visitHistory.erase(it);
        }
    }

    std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Surveillance& x){
    os << "Everyone in the city" << std::endl;

    for(auto it = x.visitHistory.begin(); it != x.visitHistory.end(); ++it){
        os << it->first << std::endl;
    }

    os << std::endl;

    return os;
}

std::map<std::string, std::vector<std::string>>& Surveillance::getVisitHistory(){
    return visitHistory;
}