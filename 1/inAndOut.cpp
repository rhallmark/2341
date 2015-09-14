//This is our read in class
#include "inAndOut.h"
#include "player.h"
using namespace std;


inAndOut::inAndOut(){
	teamTotalScore = 0; //initializes the total score of the team to zero
}

void inAndOut::setFileName(string fileName){
	nameOfFile = fileName;
	cout << "Here I will be reading data in from " << nameOfFile << "..." << endl;
}

string inAndOut::getFileName(){
	return nameOfFile;
}

string inAndOut::getTeamName(){
	return teamName;
}

string inAndOut::getNumberOfPlayers(){
	return numberOfPlayers;
}

//this is to read in each individual team file into the vectors
void inAndOut::readPlayers(){
	ifstream OpenedFile(nameOfFile.c_str());
	string teamData;

	getline(OpenedFile, teamName);
	getline(OpenedFile, numberOfPlayers);

	for(int i = 0; i < atoi(numberOfPlayers.c_str()); i++)
	{
		getline(OpenedFile, teamData);
		player sendData(teamData); //creates a temporary player object to send the data to
		playerList.push_back(sendData); //uses the vector to push the player object onto that vector for that team **Fontenots talk
	}

	OpenedFile.close();
}

void inAndOut::readMatch(){
	ifstream OpenedFile(nameOfFile.c_str());
	string numberOfEntries;
	string matchData;

	getline(OpenedFile, numberOfEntries);

	for(int i = 0; i < atoi(numberOfEntries.c_str()); i++)
	{
		getline(OpenedFile, matchData);
		encounter sendData(matchData); //creates a temporary player object to send the data to
		encounterList.push_back(sendData); //uses the vector to push the player object onto that vector for that team **Fontenots talk
	}

	OpenedFile.close();

}



void inAndOut::displayPlayers()
{
	cout << "Number of players in " << nameOfFile << " is: " << playerList.size() << endl;
	for(int i = 0; i < playerList.size(); i++)
	{
		cout << "For player: " << (i + 1) << endl;
		cout << "     Code Name: " << playerList[i].getCodeName() << endl;
		cout << "     Code Number: " << playerList[i].getCodeNumber() << endl;
	}
}

void inAndOut::displayMatch()
{
	cout << "Number of encounters in " << nameOfFile << " is: " << encounterList.size() << endl;
	for(int i = 0; i < encounterList.size(); i++)
	{
		cout << "For entry: " << (i + 1) << endl;
		cout << "     Tagger ID: " << encounterList[i].getTaggerID() << endl;
		cout << "     Target ID: " << encounterList[i].getTargetID() << endl;
		cout << "     MiliSeconds Since Match Started: " << encounterList[i].getMsSinceMatchStarted() << endl;
		cout << "     Location ID: " << encounterList[i].getLocationID() << endl;
	}
}


encounter * inAndOut::getEncounterPtr()
{
	return &(encounterList[0]);

}

int inAndOut::getEncounterListSize(){
	return encounterList.size();
}

player * inAndOut::getPlayerPtr()
{
	return &(playerList[0]);
}

int inAndOut::getPlayerListSize(){
	return playerList.size();
}


void inAndOut::sortPlayerList(){
	sort(playerList.begin(), playerList.end());
}


int inAndOut::doSomeMath(){

bestScorerLocation = 0;


	for(int i = 0; i < playerList.size(); i++)
	{
		cout << playerList[i].getTotalPoints() << endl;
		teamTotalScore = (teamTotalScore + playerList[i].getTotalPoints());

		if(playerList[i].getTotalPoints() > playerList[bestScorerLocation].getTotalPoints())
		{
			bestScorerLocation = i;
		}
	}

	return teamTotalScore;
}

string inAndOut::getBestScorer(){
	return playerList[bestScorerLocation].getCodeName();
}

int inAndOut::getBestScore(){
	return playerList[bestScorerLocation].getTotalPoints();
}