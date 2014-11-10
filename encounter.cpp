#include <iostream>
#include <ctime>
#include <cstdlib>
using std::cout;
using std::endl;

class stats{
public:
    int attack;
    int maxdefense;
    int defense;
    int hp;
    int maxhp;
    int armor;
    int mp;
    int maxmp;
	stats encounter();
    };
    
class magic{
public:
    int fireball;
    int fireball_cost;
    int healing_touch;
    int healing_touch_cost;
    int ward;
    int ward_cost;
    };

stats encounter(){
	int roll;

	stats troll;
		troll.attack = 7;
		troll.maxdefense = 4;
		troll.defense = 4;
		troll.hp = 10;
		troll.maxhp = 25;
		troll.armor = 14;
		troll.mp = 0;
		troll.maxmp = 0;

	stats goblin;
		goblin.attack = 3;
		goblin.maxdefense = 1;
		goblin.defense = 1;
		goblin.hp = 7;
		goblin.maxhp = 7;
		goblin.armor = 15;
		goblin.mp = 0;
		goblin.maxmp = 0;

	stats orc;
		orc.attack = 5;
		orc.maxdefense = 3;
		orc.defense = 3;
		orc.hp = 16;
		orc.maxhp = 16;
		orc.armor = 16;
		orc.mp = 0;
		orc.maxmp = 0;

	srand (time(0));
	roll = (rand() % 3)+1;
	if (roll ==1){
		cout << "You are attacked by a Troll!" << endl;
		return troll;
	}
	else if (roll == 2){
		cout << "You are attacked by a Goblin!" << endl;
		return goblin;
	}
	else if (roll == 3){
		cout << "You are attacked by a Orc!" << endl;
		return orc;
	}
	else{
		cout << "You find nothing." << endl;
	}
}
