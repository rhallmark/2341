#include "encounter.h"

using namespace std;

//Default to create a ___ object
encounter::encounter(std::string matchStats){
    stringstream streamForMatchFile(matchStats);
    streamForMatchFile >> taggerID;
    streamForMatchFile >> targetID;
    streamForMatchFile >> msSinceMatchStarted;
    streamForMatchFile >> locationID;
}


//Getters for fileIn objects for matches
int encounter::getTaggerID(){
    return taggerID;
}


int encounter::getTargetID(){
    return targetID;
}


int encounter::getMsSinceMatchStarted(){
    return msSinceMatchStarted;
}


int encounter::getLocationID(){
    return locationID;
}
