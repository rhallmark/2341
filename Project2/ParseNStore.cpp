#include "ParseNStore.h"

ParseNStore::ParseNStore(char ** words, int ** pages)
: words(words), pages(pages){

    wordNumber = 0; //initializing word number
    C_wordNumber = 0;
    resizeTracker = 0;

    charPerWord = new int[25];

    //first initialize them all to zero
    for(int i = 0; i < 25; i++)
    {
        charPerWord[i] = 0;
    }

        

}


void ParseNStore::setVariables()
{

}



void ParseNStore::parseLine(char lineBuffer[], int currentPageNumber){

    char* temp_chars;

    if(lineBuffer[0] == '<')
    {
          //If it is recognized as a line with a page number, Do nothing
    }



    else //parse the given line
    {

        //Fix for allocation of words in memory... setting intials to 10 and creating a resize class...
        /*
        Just some thoughts...

        Things I need to resize
        1. CharPerWord array... an integer array of the number of characters per word.. total spots in array = total number of words
        2. words[x] the actual word array which is also bassically just the number of words..
        3. When I get a pages array that corresponds to words, that would need it
        4. the array for ints that corresponds to which pages each word is on.

        take care of 1 and 2 now...
        if int resizeTracker > 10, call resize... in resize function/class set the resize int =0
        resize tracker should increment any time charPerWord array is incremented..

        **Something to note with the resize function:
        It may seem like it is not completing at the correct time, that is only because it is resizing etc. prior to the actual
        implementation of the parsing. It will resize it IF during the initial parsing to find the character size of each word,
        it finds that there are more than 10 words, then it will resize 1-4 and set the resize variable back equal to 0
        */
        std::cout << "word number is: " << C_wordNumber << std::endl;
        std::cout << "resize tracker is: " << resizeTracker << std::endl;
        if(resizeTracker > 9)
        {
            //call resize function for 1-4 above.
            resizer.activate();
            std::cout << "Address of characterPerWord Array..." << &charPerWord << std::endl;
            std::cout << "Inside of just charperword is..." << charPerWord << std::endl;
            resizer.charPerWordArray(*&charPerWord, C_wordNumber);
            resizer.wordsArray(**&words, C_wordNumber);
            resizeTracker = 0;
            std::cout << "char per word array in 1 should be 55..." << charPerWord[1] << std::endl;
            std::cout << "Address of characterPerWord Array..." << &charPerWord << std::endl;

        }



        //This block of code parses through the document merely to determine the appropiate amount of memory to allocate for each indidual word
        int C_totalCharPerLine = 0; //Specifically for counting the number of characters per word
        int C_charNumber = 0; //Specifically for counting the number of characters per word
        

        while(C_totalCharPerLine < (strlen(lineBuffer)))
        {
            if(lineBuffer[C_totalCharPerLine] != '[')
            {
                if(lineBuffer[C_totalCharPerLine] == ' ')
                {
                    std::cout << "word number is: " << C_wordNumber << std::endl;
                    std::cout << "resize tracker is: " << resizeTracker << std::endl;
                    if(resizeTracker > 9)
                    {
                        resizer.activate();
                        std::cout << "Address of characterPerWord Array..." << &charPerWord << std::endl;
                        std::cout << "Inside of just charperword is..." << charPerWord << std::endl;
                        resizer.charPerWordArray(*&charPerWord, C_wordNumber);
                        resizer.wordsArray(**&words, C_wordNumber);
                        //call resize function for 1-4 above.
                        resizeTracker = 0;
                        std::cout << "char per word array in 1 should be 55..." << charPerWord[1] << std::endl;
                        std::cout << "Address of characterPerWord Array..." << &charPerWord << std::endl;


                    }

                    C_totalCharPerLine++; //go to the next character in the line
                    C_wordNumber++; //increases the word number.. basically saying, I've counted everything in pervious word, start another
                    charPerWord[C_wordNumber] = 0; //initializing characters per word of that specific word to 0
                    resizeTracker++; // in order to determine when things need to be resized.

                }   

                else
                {
                    charPerWord[C_wordNumber] += 1; //this is another letter in the word at C_wordNumber
                    C_totalCharPerLine++; //go to next character in the line
                }
            }

            else if(lineBuffer[C_totalCharPerLine] == '[')
            {
                C_totalCharPerLine++; //increment to get rid of the first [

                while(lineBuffer[C_totalCharPerLine] != ']')
                {
                    charPerWord[C_wordNumber] += 1; //this is another letter in the word at C_wordNumber (Only this is in a [])
                    C_totalCharPerLine++; //move to next character
                    //C_charNumber++; useless
                }

                //takes us one more past the ']' symbol
                C_totalCharPerLine++;
                //C_charNumber++;
            }

        }

        int totalCharPerLine = 0;
        int charNumber = 0;

        //Dynamically allocates the perfect space for chars that will fill it
        words[wordNumber] = new char[charPerWord[wordNumber]];
        pages[wordNumber] = new int[1];
        pages[wordNumber][0] = currentPageNumber;
        std::cout << "Word[" << wordNumber << "] is being allocated with: " << charPerWord[wordNumber] << " letters!" << std::endl;


        //This block of code actually parses the document and stores it in the correct amount of memory.
        while(totalCharPerLine < (strlen(lineBuffer)))
        {

            if(lineBuffer[totalCharPerLine] != '[')
            {
                if(lineBuffer[totalCharPerLine] == ' ')
                {
                    totalCharPerLine++;
                    wordNumber++;
                    //I'm very proud of the next line... Dynamically allocates the perfect space for chars that will fill it
                    words[wordNumber] = new char[charPerWord[wordNumber]];
                    pages[wordNumber] = new int[1];
                    pages[wordNumber][0] = currentPageNumber;
                    std::cout << "Word[" << wordNumber << "] is being allocated with: " << charPerWord[wordNumber] << " letters!" << std::endl;
                    charNumber = 0;
                }

                else
                {
                    words[wordNumber][charNumber] = (lineBuffer[totalCharPerLine]);
                    totalCharPerLine++;
                    charNumber++; 
                }
            }

            else if(lineBuffer[totalCharPerLine] == '[')
            {
                totalCharPerLine++; //increment to get rid of the first [

                while(lineBuffer[totalCharPerLine] != ']')
                {
                    words[wordNumber][charNumber] = (lineBuffer[totalCharPerLine]);
                    totalCharPerLine++;
                    charNumber++;
                }

                //takes us one more past the ']' symbol
                totalCharPerLine++;
                charNumber++;
            }

        }

        C_wordNumber++;
        wordNumber++;
        resizeTracker++; // in order to determine when things need to be resized.
    }


}


int ParseNStore::getTotalNumberOfWords(){

    //as long as this is called after all words have been parsed, it should work
    return wordNumber;
}