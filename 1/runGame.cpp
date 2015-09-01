#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <exception>







	string levelOfVerbosity = "null";

	//This function will read in the files
	
	
	//This function will obtain the data from the files
	
	
	//This function determines level of verbosity


	//This function does the calculations depending on the level of verbosity


	//This function outputs the answers depending on the level of verbosity


	//cleanup



	while(true){
	
		cout << "=========================================" << endl;
		cout << "---------Welcome to Laser Tag------------" << endl;
		cout << "-----------------------------------------" << endl;

		//list the files here
		cout << "The files that I will be comparing are . . . " << endl;

		//determine verbosity
		cout << "Please choose from the following by entering the integer that corresponds to the level of verbosity that you want: "
		cout << "1). vlow" << endl;
		cout << "2). vmed" << endl;
		cout << "3). vhigh" << endl;
		cout << "0). Quit" << endl;
		cout << "=========================================\n\n" << endl;

		cin >> run;

		if(run == "0"){
			break;
		}

		else if(run == "1"){
			cout << "vlow" << endl;
		}

		else if(run == "2"){
			cout << "vmed" << endl;
		}

		else if(run == "3"){
			cout << "vhigh" << endl;
		}

		else{
			cout << "Please Try Again . . .\n" << endl;
		}
	}