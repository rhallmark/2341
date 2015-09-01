#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <exception>



//supposed to have some sort of public and private shit going on AND supposed to have it synched up all nice with the header file...



	string levelOfVerbosity = "null";


	//Here I will declare pointers to character arrays for the information from the three different places


	//ReadIn object created for team1
	//text file name is passed and data is obtained via the function


	//ReadIn object created for team2
	//text file name is passed and data is obtained via the function


	//ReadIn object created for match
	//text file name is passed and data is obtained via the function



	while(true){
	
		cout << "=========================================" << endl;
		cout << "---------Welcome to Laser Tag------------" << endl;
		cout << "-----------------------------------------" << endl;

		//list the files here
		cout << "The files that I will be comparing are . . . " << endl; //File Names go here

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
			//call sort.vlow
		}

		else if(run == "2"){
			cout << "vmed" << endl;
			//call sort.vmed
		}

		else if(run == "3"){
			cout << "vhigh" << endl;
			//call sort.vhigh
		}

		else{
			cout << "Please Try Again . . .\n" << endl;
		}
	}