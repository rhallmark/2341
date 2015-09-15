//This is our inAndOut class
#include "inAndOut.h"

using namespace std;


inAndOut::inAndOut(){
	//initializes the total score of each team to zero
    teamTotalScore = 0;
}

/*
----------To Read In----------
*/
/*This block of code is to used read in each individual 
team file. It sends the data from each line of the file
to a player object and that player object is then pushed 
onto a vector of player objects containing all of the 
player objects on team "nameOfFile"
*/
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

//Does the same as readPlayers, but for each line of the match file
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



/*
----------Sorting----------
*/
void inAndOut::sortPlayerList(){
    sort(playerList.begin(), playerList.end());
}



/*
----------Do Some Math----------
*/
/*
This function will determine the array location of the best 
scorer for each team set the member variable equal to the value it finds.
Additionally, it will add up the total team score and return it
*/
int inAndOut::doSomeMath(){

	bestScorerLocation = 0;

    for(int i = 0; i < playerList.size(); i++)
    {
        teamTotalScore = (teamTotalScore + playerList[i].getTotalPoints());
        if(playerList[i].getTotalPoints() > playerList[bestScorerLocation].getTotalPoints())
        {
            bestScorerLocation = i;
        }
    }
    return teamTotalScore;
}



/*
----------Setters----------
*/
void inAndOut::setFileName(string fileName){
    nameOfFile = fileName;
}



/*
----------Getters----------
*/
string inAndOut::getFileName(){
    return nameOfFile;
}

string inAndOut::getTeamName(){
    return teamName;
}

string inAndOut::getNumberOfPlayers(){
    return numberOfPlayers;
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

string inAndOut::getBestScorer(){
    return playerList[bestScorerLocation].getCodeName();
}

int inAndOut::getBestScore(){
    return playerList[bestScorerLocation].getTotalPoints();
}



/*
----------Testing----------
*/
/*
These are testing functions for use with debugging
the output I received and for sorting.

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
*/