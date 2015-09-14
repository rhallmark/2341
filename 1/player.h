#ifndef PLAYER_H
#define PLAYER_H
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

class player
{
    public:
        player(std::string playerStats); //ultimately, player stats is just going to be a single line from the text file of the given team

        std::string getCodeName() const;
        int getCodeNumber();
        int getTotalPoints();
        void tags(int tags, std::string taggedName, int tagLocation, bool didNotScore);
        void displayTags();
        int totalHits();
        int getTotalHits();
        int totalPoints; //probably should be private

    //private:
        int codeNumber;
        std::string codeName;
        std::vector<int> tagNumberList;
        std::vector<int> tagLocationList;
        std::vector<std::string> tagNameList;
        std::vector<int> numberOfHits;
        int costOfPoints[5];


};


bool operator<(const player &p1, const player &p2);



#endif // PLAYER_H
