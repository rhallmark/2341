#include "IO.h"

using namespace std;

IO::IO(char ** words, int ** pages, char * inputFileName, char * outputFileName)
    : words(words), pages(pages), inputFileName(inputFileName), outputFileName(outputFileName){
    //This will pass the addresses of the two arrays.
    //Will also pass in file names

    totalNumberOfWords = 0;
}

/*
----------To Read In----------
*/
void IO::readFile(){

    ParseNStore parsing(words, pages);
    //create in header once I get everything else straightened out
    
    //parsing.displayPtrs(); I think this guy is useless

    ifstream OpenedFile(inputFileName);

    //Here is my statically allocated array holding up to 80 chars
    char lineBuffer[80];
    char * findPageNumber;
    int currentPageNumber = -1;


    //Itterates through the file
    while(!OpenedFile.eof())
    {
        /*
        *This gets each line from the opened file as a char array
        */
        OpenedFile.getline(lineBuffer, sizeof(lineBuffer));


        /*
        *This will determine if each individual line is a page number.
        *If it is a page number, it will set the page number to the
        *Correct value for all future character arrays, until 
        *another page number is encountered.
        */
        if(lineBuffer[0] == '<')
        {
            findPageNumber = strtok(lineBuffer, "<>");
            currentPageNumber = atoi(findPageNumber);
        }


        /*
        This line sends the line to get parsed & the page # that 
        all words residing on that line are associated with...
        */
        parsing.parseLine(lineBuffer, currentPageNumber); 
    }


    totalNumberOfWords = parsing.getTotalNumberOfWords();

}


//This will write the stuff to a file..
void IO::writeFile(){
    
	ofstream outFile;
    outFile.open(outputFileName);

    for(int i = 0; i < totalNumberOfWords; i++)
    {
        outFile << words[i] << ": " << pages[i][0] << std::endl;
    }




    outFile.close();




}


/*
----------Setters----------
*/



/*
----------Getters----------
*/
