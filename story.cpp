#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

using std::ofstream;
using std::ifstream;
using std::string;

void story(int chapstart, int chapend){
	string line;
	ifstream myfile("story.txt");
	if (myfile.is_open()){
		for (int i = 0; i <= chapend; i++){
			getline(myfile, line);
			if (i >= chapstart && i <= chapend){
				std::cout << line << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(500)); //pauses the program for a 1/2 second
			}//end of inner if
			else{}
		}//end of while
		myfile.close();
	}//end of if
	else{
		std::cout << "The Grand Tome has been Lost." << std::endl;
	}//end of else
}

