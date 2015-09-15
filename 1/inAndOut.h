//header file for inAndOut class
#ifndef INANDOUT_H
#define INANDOUT_H
#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include <vector>
#include <algorithm>
#include "player.h"
#include "encounter.h"

//Header File is where we put all of a classes function prototypes and variable declarations
class inAndOut{

    public:
        inAndOut();
        void setFileName(std::string fileName);
        std::string getFileName();
        void readPlayers();
        void readMatch();
        encounter * getEncounterPtr();
        player * getPlayerPtr();
        void sortPlayerList();
        int getEncounterListSize();
        int getPlayerListSize();
        int doSomeMath();
        std::string getTeamName();
        std::string getNumberOfPlayers();
        std::string getBestScorer();
        int getBestScore();

        /* Testing
		void displayPlayers();
        void displayMatch();
        */

    protected:


    private:
        std::string nameOfFile;
        std::vector<player> playerList;
        std::vector<encounter> encounterList;
        int teamTotalScore;
        std::string teamName;
        std::string numberOfPlayers;
        int bestScorerLocation;
};


#endif // INANDOUT_H
