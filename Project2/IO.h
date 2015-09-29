#ifndef IO_H
#define IO_H
#include <cstring>
#include <iostream>
#include <fstream>
#include <exception>
#include <cstdlib>
#include "ParseNStore.h"


class IO
{
    public:
        IO(char ** words, int ** pages, char * inputFileName, char * outputFileName);
        void readFile();
        void writeFile();


    private:
        char * inputFileName;
      	char * outputFileName;
        char ** words;
        int ** pages;
        int totalNumberOfWords;

};

#endif // IO_H


