#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
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
				cout << line << endl;
			}//end of inner if
			else{}
		}//end of while
		myfile.close();
	}//end of if
	else{
		cout << "The Grand Tome has been Lost." << endl;
	}//end of else
}
