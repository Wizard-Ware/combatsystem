#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::string;

int main(){
	string line;
	ifstream myfile ("story.txt");
	if (myfile.is_open()){
		for(int i = 0; i < 4; i++){ 
			getline(myfile, line);
			if (i == 3){
				cout << line << endl;
			}//end of inner if
			else{}
		}//end of while
		myfile.close();
	}//end of if
	else{
		cout << "Unable to open file." << endl;
	}//end of else
	cout << endl << "Press Enter to close.";
	cin.get();
	return 0;
}
