#include "player.h"
#include <string>

using namespace std;

player::player(string playerStats){
    stringstream streamForPlayer(playerStats);
    streamForPlayer >> codeNumber;
    streamForPlayer >> codeName;
    costOfPoints[0] =  0;
    costOfPoints[1] =  5;
    costOfPoints[2] =  8;
    costOfPoints[3] =  10;
    costOfPoints[4] =  15;
    totalPoints = 0;


}


void player::tags(int taggedNumber, string taggedName, int tagLocation, bool didScore){

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


string player::getCodeName() const{
    return codeName;
}

int player::getCodeNumber(){
    return codeNumber;
}


bool operator<(const player &p1, const player &p2){
    if(p1.getCodeName() < p2.getCodeName())
        return true;
    else
        return false;
}



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


int player::totalHits(){
    return numberOfHits.size();
}


//adds up the nuber of hits in each spot and multiplies them to determine total number of points scored by individual DONE UP THERE^
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
