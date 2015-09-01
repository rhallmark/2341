//Laser Tag main function

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <exception>
#include "nameClass.h"
//#include "runGame.cpp"

using namespace std;

class DoSomething{
	//access specifier is... private vs public etc
	public:
		//constructorrrr
		DoSomething(string passedString){
			setName(passedString);
		}

		DoSomething(string first, string last){
			setFirstAndLast(first, last);
		}

		void setName(string x){
			name = x;
		}

		void setFirstAndLast(string x, string y){
			name = x + " " + y;
		}

		string getName(){
			return name;
		}

	private:
		string name;

};


int main(){

	//"Get the ball rolling" function--haha
	DoSomething dsObj("LuckyBuckyRoberts");

	DoSomething sixtytwo("This is the SEcond one", "And this one too");

	//dsObj.setName("Testy Man");
	cout << dsObj.getName() << endl;
	cout << sixtytwo.getName() << endl;


	nameClass testName;

    return 0;
}

