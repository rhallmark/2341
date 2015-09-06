//Laser Tag main function

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <exception>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <exception>
//#include "nameClass.h"
//#include "runGame.cpp"

using namespace std;

void runGame();

int main(int argc, char* argv[]){

	//"Get the ball rolling" function--haha
	
	cout << "argc = " << argc << endl;
    
    for(int i = 0; i < argc; i++)
    	{
    	cout << "argv[" << i << "] = " << argv[i] << endl;
		}

	runGame();


    return 0;
}


void runGame(){

	cout << "Hello" << endl;

	string levelOfVerbosity = "null";

	if(levelOfVerbosity == "vlow"){
		cout << "vlow" << endl;
		//call sort.vlow
		}

	else if(levelOfVerbosity == "vmed"){
			cout << "vmed" << endl;
			//call sort.vmed
		}

	else if(levelOfVerbosity == "vhigh"){
			cout << "vhigh" << endl;
			//call sort.vhigh
		}

	else{
			cout << "Incorrect Verbosity . . ." << endl;
			cout << "Please run again with vlow, vmed, or vhigh." << endl;
		}

}