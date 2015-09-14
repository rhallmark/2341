//Laser Tag main function
#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <cstdlib>
#include "runGame.h"


using namespace std;

void initiateGame(int, char**);
void argCheck(int, char**);

//"Get the ball rolling" function--haha
int main(int argc, char* argv[]){


	//This block of code will determine if acceptable arguments were passed
	argCheck(argc, argv);


	//This block of code will kick off / initiate the game with the given arguments
	initiateGame(argc, argv);


    return 0;
}

//Function to kick off / initiat the game, given some level of verbosity
void initiateGame(int argc, char** argv){

	//Using argv to set file names for easy access
	string programName = argv[0];
	string team1FileName = argv[1];
	string team2FileName = argv[2];
	string matchFileName = argv[3];
	string outputFileName = argv[4];
	string verbosityLevel = argv[5];


	//Testing to see which level of verbosity & running code given that level
	if((verbosityLevel == "vlow") || (verbosityLevel == "vmed") || (verbosityLevel == "vhigh") ) {
		runGame Game = runGame(programName, team1FileName, team2FileName, matchFileName, outputFileName, verbosityLevel);
		Game.getInformation();
		Game.sort();
		Game.outputToFile();
		cout << "DONE " << endl;
		}

	else{
		cout << "Incorrect Verbosity . . ." << endl;
		cout << "Please run again with vlow, vmed, or vhigh." << endl;
		}

}


//Function to check the arguments
void argCheck(int argc, char** argv){

	/*
	This block of code will display all arguments -- uncomment for troubleshooting
	cout << "argc = " << argc << endl;
    for(int i = 0; i < argc; i++)
    	{
    	cout << "argv[" << i << "] = " << argv[i] << "  and the addres is: " << &argv[i] << endl;
		}
	*/


	//This block of code will check for the correct NUMBER of arguments
	if (argc != 6)
		{
		cout << "You have intered an incorrect number of arguments, please try again following this example:" << endl;
		cout << "./a.out TeamA.txt TeamB.txt MatchFile.txt OutputFile.txt verbosity" << endl;
		cout << "Verbosity can be either: vlow, vmed, or vhigh" << endl;
		exit(1);
		}

}
