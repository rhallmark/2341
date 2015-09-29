#ifndef PARSENSTORE_H
#define PARSENSTORE_H
#include <cstring>
#include <iostream>
#include <fstream>
#include <exception>
#include "Resize.h"


class ParseNStore
{
    public:
        ParseNStore(char ** words, int ** pages);
        void setVariables();
        void parseLine(char lineBuffer[], int currentPageNumber);
        int getTotalNumberOfWords();


    private:
        char ** words;
        int ** pages;
        int wordNumber;
        int * charPerWord;
        int C_wordNumber;
        int resizeTracker;
        Resize resizer;
};

#endif // PARSENSTORE_H




