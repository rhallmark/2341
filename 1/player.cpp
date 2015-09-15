#include "player.h"

using namespace std;



/*
This block of codes takes the line that was passed
to it and parses it into each individual player object
*/
player::player(string playerStats){
    stringstream streamForPlayer(playerStats);
    streamForPlayer >> codeNumber;
    streamForPlayer >> codeName;
    
    //This gives a corresponding point value
    //to a target location.
    costOfPoints[0] =  0;
    costOfPoints[1] =  5;
    costOfPoints[2] =  8;
    costOfPoints[3] =  10;
    costOfPoints[4] =  15;

    //This confirms that every player starts with 0 total points
    totalPoints = 0;
}



/*
This block of code will add up the total number of
tags that a single player had on all players of the 
opposing team. Additionally, it will keep track of
the tagged name, tagged number, and tagged location
of each tag.
*/
void player::tags(int taggedNumber, string taggedName, int tagLocation){

    bool checkForReitterate = true;

    if(tagLocation != 0)
    {
        for(int i = 0; i < tagNumberList.size(); i++)
        {
            if(taggedNumber == tagNumberList[i])
                {
                    //increment
                    numberOfHits[i] = (numberOfHits[i] + 1);
                    tagLocationList[i] = tagLocation;
                    checkForReitterate = false;
                }
        }

        if(checkForReitterate == true)
        {
            //add vectors normally
            tagNumberList.push_back(taggedNumber);
            tagNameList.push_back(taggedName);
            tagLocationList.push_back(tagLocation);
            numberOfHits.push_back(1);
        }
    }

    else if(tagLocation == 0)
    {
        tagNumberList.push_back(taggedNumber);
        tagNameList.push_back(taggedName);
        tagLocationList.push_back(tagLocation);
        numberOfHits.push_back(0);
    }


    totalPoints = totalPoints + (costOfPoints[tagLocation]);

}



/*
----------Overloaded Operator for Sorting----------
*/
bool operator<(const player &p1, const player &p2){
    if(p1.getCodeName() < p2.getCodeName())
        return true;
    else
        return false;
}



/*
----------Getters----------
*/
string player::getCodeName() const{
    return codeName;
}

int player::getCodeNumber(){
    return codeNumber;
}

int player::getTotalPoints(){
    return totalPoints;
}

int player::getTotalHits(){

    int hits = 0;

    for(int i = 0; i < numberOfHits.size(); i++)
    {
        if(numberOfHits[i] >= 1)
        {
            hits++;
        }
    }

    return hits;
}


/*
----------Testing----------
*/
/*
This is a testing function to display the tags of
each player. Used when testing high verbosity
void player::displayTags(){

    for(int i = 0; i < tagNumberList.size(); i++)
    {
        if(numberOfHits[i] != 1)
        {
            cout <<  getCodeName() << " tagged " << tagNameList[i] << " " << numberOfHits[i] << " times" << endl;
        }
        else if(numberOfHits[i] == 1)
        {
            cout <<  getCodeName() << " tagged " << tagNameList[i] << " " << numberOfHits[i] << " time" << endl;
        }
    }
}
*/