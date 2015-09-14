//header file for runGame class
#ifndef RUNGAME_H
#define RUNGAME_H
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <iostream>
#include "encounter.h"
#include "player.h"
#include "inAndOut.h"

//Header File is where we put all of a classes function prototypes and variable declarations
class runGame{

	public:
		runGame();
		runGame(std::string programName, std::string team1FileName, std::string team2FileName, std::string matchFileName, std::string outputFileName, std::string verbosityLevel);
		//runGame(string, string, string, string, string, string);
		void getInformation();
		void sort();
		void outputToFile();
		//bool sort1(const player &p1, const player &p2);
		void runVlow();
		void runVmed();
		void runVhigh();


	private:
		const std::string programName;
		const std::string team1FileName;
		const std::string team2FileName;
		const std::string matchFileName;
		const std::string outputFileName;
		const std::string verbosityLevel;

		encounter* encounterList;
		int encounterListSize;
		player* team1List;
		int team1ListSize;
		player* team2List;
		int team2ListSize;

		inAndOut ReadingFromTeam1;
		inAndOut ReadingFromTeam2;
		inAndOut ReadingFromMatch;
		int team1Score;
		int team2Score;
};


#endif // RUNGAME_H