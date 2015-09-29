#include "Resize.h"

Resize::Resize()
{
    std::cout << "&&&&&&&&&&&&&&&&&&&I am a resize object!&&&&&&&&&&&&&&&&&&&" << std::endl;
}


void Resize::activate(){
	std::cout << "___________________I am a resize object!___________________" << std::endl;
    std::cout << "^^^^^^^^^^^^^^^^^^^I have been activated!^^^^^^^^^^^^^^^^^^" << std::endl;

    //Here will be all the fun resizing!



}


void Resize::charPerWordArray(int *&intArray, int size){
	std::cout << "I am the character per word array pointer resizer." << std::endl;
	std::cout << "The *&intarray.. is: " << *&intArray << std::endl;
	std::cout << "The intarray.. is: " << intArray << std::endl;

	std::cout << "The array size is: " << size << std::endl;

	int * tempArray;


	tempArray = new int[size + 10];

	for(int i = 0; i < size+10; i++)
	{
		tempArray[i] = 0;
	}


	for(int i = 0; i < size; i++)
	{
		tempArray[i] = intArray[i];
		std::cout << "tempArray[" << i << "]= " << tempArray[i] << std::endl;
		std::cout << "intArray[" << i << "]= " << intArray[i] << std::endl;

	}


	for(int i = 0; i < size+10; i++)
	{
		std::cout << "The tempArray[" << i << "].. is: " << tempArray[i] << std::endl;
	}

	std::cout << "The tempArray.. is: " << tempArray << std::endl;

	delete[] intArray;
	intArray = tempArray;

}


void Resize::wordsArray(char **&wordPtrArray, int size){

	char ** tempArray;
	tempArray = new char*[size + 10];

	for(int i = 0; i < size+10; i++)
	{
		tempArray[i] = NULL;
	}


	for(int i = 0; i < size; i++)
	{
		tempArray[i] = wordPtrArray[i];
		//std::cout << "tempArray[" << i << "]= " << tempArray[i] << std::endl;
		//std::cout << "wordPtrArray[" << i << "]= " << wordPtrArray[i] << std::endl;
	}


	delete[] wordPtrArray;
	wordPtrArray = tempArray;

}