//AutoIndexer main function
#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <cstdlib>
#include "IO.h"

using namespace std;

void argCheck(int, char**);
void autoIndexer(int, char**);



//This is pretty much Version  0.8 of my program... 
/*
So there are a lot of issues right still, let me list them out for you...

MAD DASH TO THE FINISH LINE!

Currently, my program has certain capabilities and is lacking in certain areas.
BAD: See numbers 1, 4, and 7 below.
GOOD: See everything else.

1. I have no ability to distinguish that  'tree' and 'tree' or 'Tree' are the same thing.... that means that 'tree' on page 4 and 'tree' on page 64 will be two different entries.. 
meaning that the int array of pages will only need to have 1 space hahahaha... 
THIS IS PRIORITY NUMBER 1. otherwise it's not even a real indexer 
To reitterate, priority 1 is to be able to distinguish if a word is already in the array. maybe string compare?

2. ***FIXED WITH UPDATE 0.6 **** I have no ability to see how long a word is before I put it into memory... for isntance, the word could be 4 characters, but I'm allocating 40 for each word
The fix I will propose is to do the entire itteration through the individual line first, have a temporary array of ints and then as they are created, dynamically allocate with that int instead of '40'
THIS IS PRIORITY NUMBER 2

3. ***FIXED WITH UPDATE 0.8 **** 
I do not have the ability to resize anything. (I am temporarily using a larger amount than I need of dynamic mem to cover this... 25 as seen up there ^)

4. There is no order whatsoever. Not alphabetical.. nothing....

5. ***FIXED WITH UPDATE 0.7**** There is no output whatsoever. NADA.

6. ***FIXED WITH UPDATE 0.7**** Keep track of page numbers.. ish

7. my character and integer memory is not being cleaned up at the moment.. This is a must!
*/




int main(int argc, char* argv[]){

    //This block of code will determine if acceptable arguments were passed
    argCheck(argc, argv);

    //Function to initiate indexing with the given arguments
    autoIndexer(argc, argv);



    return 0;
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
    if (argc != 3)
        {
        cout << "You have intered an incorrect number of arguments, please try again following this example:" << endl;
        cout << "./indexer input.txt index.output" << endl;
        exit(1);
        }

}


//Function to initiate indexing with the given arguments
void autoIndexer(int argc, char** argv){

    //Using argv to set file names for easy access
    char * programName = argv[0];
    char * inputFileName = argv[1];
    char * outputFileName = argv[2];

    //This is for testing and debugging purposes of input file name
    //inputFileName = (char*)"input.txt";


    //Create the initial character & int arrays with dynamic memory
    //Purpose of these arrays is to store pointers to the words and pages
    char ** words = new char*[25];
    int ** pages = new int*[25];

    //words[0] = (char*)"testing1";
    //words[1] = (char*)"Testing 2";


    //Create a ReadIn object
    IO autoIndexedFile(words, pages, inputFileName, outputFileName);
    autoIndexedFile.readFile();
    autoIndexedFile.writeFile();

        //new words 0
    // cout << "new words[" << "0" << "] = " << words[0] << endl;

    // cout << "new words[" << "1" << "] = " << words[1] << endl;

    // cout << " should be u " << words[0][1] << endl;

    //Free the memory of the two initial arrays
    delete[] words;
    delete[] pages;
}


