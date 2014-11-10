#include <iostream>
#include <ctime>
#include <cstdlib>
using std::cout;
using std::endl;

void fireball(int cost, int &MP, int damage, int &mobHealth){

}

void healing(int cost, int &MP, int healing, int maxHP, int &HP){
	if(MP >= cost){
		HP += healing;
		MP -= cost;
		cout << "The power of divine magic runs through you and heals your wounds." << endl;
		if(HP > maxHP){
			HP = maxHP;
			cout << "You have been healed to full life." << endl;
		}//end of inner if
	}//end of outer if
	else{
		cout << "You don't have sufficiant MP to cast this spell." << endl;
	}
}

void ward(int cost, int &MP, int amount, int maxDEF, int &def){
	if(MP >= cost){
		def += amount;
		MP -= cost;
		cout << "Your armor shines with an Arcane power empowering it." << endl;
		if(def > maxDEF){
			def = maxDEF;
			cout << "Your defense has been raised to max." << endl;
		}//end of inner if
	}//end of outer if
	else{
		cout << "You don't have sufficiant MP to cast this spell." << endl;
	}
}
