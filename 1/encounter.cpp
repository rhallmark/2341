#include "encounter.h"

using namespace std;

/*
This block of codes takes the line that was passed
to it and parses it into each individual line of match
statistics object. To be honest, this is probably
horribly inefficient and likely a big possibility for
failure since this is all on the stack.
*/
encounter::encounter(std::string matchStats){
    stringstream streamForMatchFile(matchStats);
    streamForMatchFile >> taggerID;
    streamForMatchFile >> targetID;
    streamForMatchFile >> msSinceMatchStarted;
    streamForMatchFile >> locationID;
}


/*
----------Getters----------
*/
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
