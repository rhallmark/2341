#ifndef ENCOUNTER_H
#define ENCOUNTER_H
#include <sstream>
#include <string>

class encounter
{
    public:
        encounter(std::string matchStats);

        int getTaggerID();
        int getTargetID();
        int getMsSinceMatchStarted();
        int getLocationID();

    private:
        int taggerID;
        int targetID;
        int msSinceMatchStarted;
        int locationID;
};

#endif // ENCOUNTER_H
