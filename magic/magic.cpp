#include <iostream>
#include <ctime>
#include <cstdlib>
using std::cout;
using std::endl;

void fireball(int cost, int &MP, int firedamage, int &mobHealth, int mobarmor, int mobdef){
	int roll = 0;
	int damage;
	if (MP >= cost){
		MP -= cost;
		srand(time(0) + 3);
		roll = (rand() % 20) + 1;
		if (roll == 20){
			damage = (firedamage * 2);
			mobHealth -= damage;
			cout << "You score a critital hit!" << endl;
			cout << "Your fireball does " << damage << " points of damage." << endl;
		}
		else if (roll + firedamage > mobarmor){
			damage = firedamage - mobdef;
			if (damage < 0){
				cout << "The fire flows over the enemy doing nothing.";
			}
			else if (damage > 0){
				mobHealth -= damage;
				cout << "Your fireball does " << damage << " points of damage." << endl;
			}
		}
		else if (roll + firedamage <= mobarmor){
			cout << "The blast of fire misses the target." << endl;
		}
	}
}

void healing(int cost, int &MP, int healing, int maxHP, int &HP){
	if (MP >= cost){
		HP += healing;
		MP -= cost;
		cout << "The power of divine magic runs through you and heals your wounds." << endl;
		if (HP > maxHP){
			HP = maxHP;
			cout << "You have been healed to full life." << endl;
		}//end of inner if
	}//end of outer if
	else{
		cout << "You don't have sufficiant MP to cast this spell." << endl;
	}
}

void ward(int cost, int &MP, int amount, int maxDEF, int &def){
	if (MP >= cost){
		def += amount;
		MP -= cost;
		cout << "Your armor shines with an Arcane power empowering it." << endl;
		if (def > maxDEF){
			def = maxDEF;
			cout << "Your defense has been raised to max." << endl;
		}//end of inner if
	}//end of outer if
	else{
		cout << "You don't have sufficiant MP to cast this spell." << endl;
	}
}
