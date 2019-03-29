//
// Created by AL on 2019-03-29.
//

#ifndef LAB08_SURVEILLANCE_HPP
#define LAB08_SURVEILLANCE_HPP

#include <string>
#include <map>
#include <vector>
#include <list>

class Surveillance {
    private:
        std::map<std::string, std::vector<std::string>> visitHistory;
    public:
        Surveillance() = default;

        std::map<std::string, std::vector<std::string>>& getVisitHistory();

        void addPersonToHistory(std::string person, const std::vector<std::string> &locations);
        bool locationVisted(std::string person, std::list<std::string> locations);
        bool locationNotVisted(std::string person, std::list<std::string> locations);
        void findRegularPeople();

        friend std::ostream& operator<<(std::ostream& os, const Surveillance& x);
};

#endif //LAB08_SURVEILLANCE_HPP
