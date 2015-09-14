#ifndef ENCOUNTER_H
#define ENCOUNTER_H
#include <sstream>
#include <string>

class encounter
{
    public:
        encounter(std::string matchStats); //merely creates an encounter object

        int getTaggerID();
        int getTargetID();
        int getMsSinceMatchStarted();
        int getLocationID();



    private:

        //private variables for the match file version
        int taggerID;
        int targetID;
        int msSinceMatchStarted;
        int locationID;

friend class output;

};

#endif // ENCOUNTER_H
