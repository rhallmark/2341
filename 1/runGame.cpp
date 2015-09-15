#include "runGame.h"



using namespace std;



runGame::runGame(string programName, string team1FileName, string team2FileName, string matchFileName, string outputFileName, string verbosityLevel)
: programName(programName), team1FileName(team1FileName), team2FileName(team2FileName), matchFileName(matchFileName), outputFileName(outputFileName), verbosityLevel(verbosityLevel){

    cout << "Verbosity = " << verbosityLevel << endl;
}



void runGame::getInformation(){
    /*
        Each of these objects is declared as a member function
    This set of objects and function calls will set the file
    Name of the appropriate inAndOut object equal to the passed
    file name. It will also read in and parse the text.
    NOTE: The commented out "displayPlayer()" function will
    display the players associated with each object to the
    command line--when testing.
        Additionally, member variables that contain pointers to
    each type of object are holding the spot of the first object
    in the vector of objects that is created in the inAndOut class
    **See inAndOut.h
    */

    ReadingFromTeam1.setFileName(team1FileName);
    ReadingFromTeam1.readPlayers();
    //ReadingFromTeam1.displayPlayers();
    team1List = ReadingFromTeam1.getPlayerPtr();
    team1ListSize = ReadingFromTeam1.getPlayerListSize();

    ReadingFromTeam2.setFileName(team2FileName);
    ReadingFromTeam2.readPlayers();
    //ReadingFromTeam2.displayPlayers();
    team2List = ReadingFromTeam2.getPlayerPtr();
    team2ListSize = ReadingFromTeam2.getPlayerListSize();

    ReadingFromMatch.setFileName(matchFileName);
    ReadingFromMatch.readMatch();
    //ReadingFromMatch.displayMatch();
    encounterList = ReadingFromMatch.getEncounterPtr();
    encounterListSize  = ReadingFromMatch.getEncounterListSize();

    //Here is where you will dock me--sorting
    //I just sorted everything alphabetically
    ReadingFromTeam1.sortPlayerList();
    ReadingFromTeam2.sortPlayerList();

    
}



void runGame::sort(){

    int taggedIndividualArrayLocation;




    /*
	*************NOTE**************
	Here it gets a little complicated... at least it was for me--haha.
	I wrote at the beginning of each 'nested for loop' what it's intended purpose was
	I had to have one of each of these for each team file.
	*******************************
    */



    //Goes through the entirety of the team 1 list to initialize all hits from team 1 to team 2 to zero
    for(int countThroughTeam1 = 0; countThroughTeam1 < team1ListSize; countThroughTeam1++)
    {
        for (int countThroughTeam2 = 0; countThroughTeam2 < team2ListSize; countThroughTeam2++)
        {
            team1List[countThroughTeam1].tags(team2List[countThroughTeam2].getCodeNumber(), team2List[countThroughTeam2].getCodeName(), 0);
        }
    }

    //Goes through the entirety of the team 1 list to add the hits that were scored in the match files
    for(int countThroughTeam1 = 0; countThroughTeam1 < team1ListSize; countThroughTeam1++)
    {
        for (int i = 0; i < encounterListSize; i++)
        {
            if((team1List[countThroughTeam1].getCodeNumber()) == (encounterList[i].getTaggerID()))
            {
                //This will find an ID to an associated name from the encounter list;
                for(int findNameToID = 0; findNameToID < team1ListSize; findNameToID++)
                {
                    if((encounterList[i].getTargetID()) == (team2List[findNameToID].getCodeNumber()) )
                        {
                            taggedIndividualArrayLocation = findNameToID;
                        }
                }
                team1List[countThroughTeam1].tags(encounterList[i].getTargetID(), team2List[taggedIndividualArrayLocation].getCodeName(), encounterList[i].getLocationID());
            }
        }
    }
    //This calculates the total score for team 1 (In addition to some other things in the math function)
    team1Score = ReadingFromTeam1.doSomeMath();






    //Goes through the entirety of the team 2 list to initialize all hits from team 2 to team 1 to zero
    for(int countThroughTeam2 = 0; countThroughTeam2 < team2ListSize; countThroughTeam2++)
    {
        for (int countThroughTeam1 = 0; countThroughTeam1 < team1ListSize; countThroughTeam1++)
        {
            team2List[countThroughTeam2].tags(team1List[countThroughTeam1].getCodeNumber(), team1List[countThroughTeam1].getCodeName(), 0);
        }
    }

    //Goes through the entirety of the team 2 list to add the hits that were scored in the match files
    for(int countThroughTeam2 = 0; countThroughTeam2 < team2ListSize; countThroughTeam2++)
    {
        for (int i = 0; i < encounterListSize; i++)
        {
            if((team2List[countThroughTeam2].getCodeNumber()) == (encounterList[i].getTaggerID()))
            {
                //This will find an ID to an associated name from the encounter list;
                for(int findNameToID = 0; findNameToID < team2ListSize; findNameToID++)
                {
                    if((encounterList[i].getTargetID()) == (team1List[findNameToID].getCodeNumber()) )
                        {
                            taggedIndividualArrayLocation = findNameToID;
                        }
                }
                team2List[countThroughTeam2].tags(encounterList[i].getTargetID(), team1List[taggedIndividualArrayLocation].getCodeName(), encounterList[i].getLocationID());
            }
        }
    }
    //This calculates the total score for team 2 (In addition to some other things in the math function)
    team2Score = ReadingFromTeam2.doSomeMath();


}



void runGame::outputToFile(){

    if(verbosityLevel == "vlow")
    {
        runGame::runVlow();
    }

    else if (verbosityLevel == "vmed")
    {
        runGame::runVmed();
    }

    else if (verbosityLevel == "vhigh")
    {
        runGame::runVhigh();
    }

    else
    {
    cout << "You really shouldn't be here... incorrect verbosity level" << endl;
    }

}



void runGame::runVlow(){
    ofstream outFile;
    outFile.open(outputFileName.c_str());

    outFile << ReadingFromTeam1.getTeamName() << ": " << team1Score << " points" << endl;
    outFile << ReadingFromTeam2.getTeamName() << ": " << team2Score << " points" << endl;

    if(team1Score < team2Score)
    {
        outFile << "Overall Winners: " << ReadingFromTeam2.getTeamName() << endl;
    }
    else if(team2Score < team1Score)
    {
        outFile << "Overall Winners: " << ReadingFromTeam1.getTeamName() << endl;
    }
    else
    {
        outFile << "Overall Winners: It is a tie" << endl;
    }

    outFile.close();

}



void runGame::runVmed(){
    ofstream outFile;
    outFile.open(outputFileName.c_str());

    outFile << ReadingFromTeam1.getTeamName() << endl;

    for(int i = 0; i < team1ListSize; i++)
    {
        //Checks to determine plurality on the word 'tag(s)'
        if(team1List[i].getTotalHits() == 1)
        {
            outFile << "     " << team1List[i].getCodeName() << " had a total of " << team1List[i].getTotalHits() << " tag" << endl;
        }
        else
            outFile << "     " << team1List[i].getCodeName() << " had a total of " << team1List[i].getTotalHits() << " tags" << endl;
    }

    outFile << "\n";

    outFile << ReadingFromTeam2.getTeamName() << endl;

    for(int i = 0; i < team2ListSize; i++)
    {
        //Checks to determine plurality on the word 'tag(s)'
        if(team2List[i].getTotalHits() == 1)
        {
            outFile << "     " << team2List[i].getCodeName() << " had a total of " << team2List[i].getTotalHits() << " tag" << endl;
        }
        else
            outFile << "     " << team2List[i].getCodeName() << " had a total of " << team2List[i].getTotalHits() << " tags" << endl;
    }

    outFile << "\n";

    outFile << "Best score from " << ReadingFromTeam1.getTeamName() << ": " << ReadingFromTeam1.getBestScorer() << " (" <<  ReadingFromTeam1.getBestScore() << " points)" << endl;
    outFile << "Best score from " << ReadingFromTeam2.getTeamName() << ": " << ReadingFromTeam2.getBestScorer() << " (" <<  ReadingFromTeam2.getBestScore() << " points)" << endl;

    outFile << ReadingFromTeam1.getTeamName() << ": " << team1Score << " points" << endl;
    outFile << ReadingFromTeam2.getTeamName() << ": " << team2Score << " points" << endl;

    if(team1Score < team2Score)
    {
        outFile << "Overall Winners: " << ReadingFromTeam2.getTeamName() << endl;
    }
    else if(team2Score < team1Score)
    {
        outFile << "Overall Winners: " << ReadingFromTeam1.getTeamName() << endl;
    }
    else
    {
        outFile << "Overall Winners: It is a tie" << endl;
    }

    outFile.close();
}



void runGame::runVhigh(){
    ofstream outFile;
    outFile.open(outputFileName.c_str());

    outFile << ReadingFromTeam1.getTeamName() << endl;

    //loop through every player in team1 to push the correct info to the file
    for(int i = 0; i < team1ListSize; i++)
    {
        //want to display every tag for every individual here
        for(int c = 0; c < team1List[i].tagNumberList.size(); c++)
        {
            if(team1List[i].numberOfHits[c] != 1)
            {
                outFile << "     " <<  team1List[i].getCodeName() << " tagged " << team1List[i].tagNameList[c] << " " << team1List[i].numberOfHits[c] << " times" << endl;
            }
            else if(team1List[i].numberOfHits[c] == 1)
            {
                outFile << "     " <<  team1List[i].getCodeName() << " tagged " << team1List[i].tagNameList[c] << " " << team1List[i].numberOfHits[c] << " time" << endl;
            }
        }

        //Checks to determine plurality on the word 'tag(s)'
        if(team1List[i].getTotalHits() == 1)
        {
            outFile << "     " << team1List[i].getCodeName() << " had a total of " << team1List[i].getTotalHits() << " tag" << endl;
        }
        else
            outFile << "     " << team1List[i].getCodeName() << " had a total of " << team1List[i].getTotalHits() << " tags" << endl;
    }

    outFile << "Best score from " << ReadingFromTeam1.getTeamName() << ": " << ReadingFromTeam1.getBestScorer() << " (" <<  ReadingFromTeam1.getBestScore() << " points)" << endl;
    outFile << ReadingFromTeam1.getTeamName() << ": " << team1Score << " points" << endl;

    outFile << "\n";

    outFile << ReadingFromTeam2.getTeamName() << endl;

    //loop through every player in team2 to push the correct info to the file
    for(int i = 0; i < team2ListSize; i++)
    {

        //want to display every tag for every individual here
        for(int c = 0; c < team2List[i].tagNumberList.size(); c++)
        {
            if(team2List[i].numberOfHits[c] != 1)
            {
                outFile << "     " <<  team2List[i].getCodeName() << " tagged " << team2List[i].tagNameList[c] << " " << team2List[i].numberOfHits[c] << " times" << endl;
            }
            else if(team2List[i].numberOfHits[c] == 1)
            {
                outFile << "     " <<  team2List[i].getCodeName() << " tagged " << team2List[i].tagNameList[c] << " " << team2List[i].numberOfHits[c] << " time" << endl;
            }
        }


        //Checks to determine plurality on the word 'tag(s)'
        if(team2List[i].getTotalHits() == 1)
        {
            outFile << "     " << team2List[i].getCodeName() << " had a total of " << team2List[i].getTotalHits() << " tag" << endl;
        }
        else
            outFile << "     " << team2List[i].getCodeName() << " had a total of " << team2List[i].getTotalHits() << " tags" << endl;
    }

    outFile << "Best score from " << ReadingFromTeam2.getTeamName() << ": " << ReadingFromTeam2.getBestScorer() << " (" <<  ReadingFromTeam2.getBestScore() << " points)" << endl;
    outFile << ReadingFromTeam2.getTeamName() << ": " << team2Score << " points" << endl;

    outFile << "\n";

    if(team1Score < team2Score)
    {
        outFile << "Overall Winners: " << ReadingFromTeam2.getTeamName() << endl;
    }
    else if(team2Score < team1Score)
    {
        outFile << "Overall Winners: " << ReadingFromTeam1.getTeamName() << endl;
    }
    else
    {
        outFile << "Overall Winners: It is a tie" << endl;
    }

    outFile.close();
}