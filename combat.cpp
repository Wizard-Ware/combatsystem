#include <iostream>
#include <ctime>
#include <cstdlib>
using std::cout;
using std::endl;

struct magic{
	int fireball;
	int fireball_cost;
	int healing_touch;
	int healing_touch_cost;
	int ward;
	int ward_cost;
};

int combat_system_mob(int atk, int armor, int health, int def, int maxhp){
	int roll, damage;
	srand(time(0) + 3);
	roll = (rand() % 20) + 1;
	if (roll == 20){
		int damage = (atk * 2) - def;
		cout << "The monster attacks and get a critital\n";
		cout << "It hits you for " << damage << " points of damage \n";
		health = health - damage;

	}
	else if (armor <= roll + atk){
		int damage = atk - def;
		cout << "The monster hits for " << damage << " points of damage \n";
		health = health - damage;

	}
	else if (armor> roll + atk){
		cout << "The monster misses you." << endl;
	}
	return health;
}

int combat_system_player(int atk, int armor, int health, int def, int maxhp){
	int roll, damage;
	srand(time(0));
	roll = (rand() % 20) + 1; //generates roll between 1 and 20
	if (roll == 20){ // if roll is a 20 they score a crit
		int damage = (atk * 2) - def;
		cout << "You swing your sword and get a critital\n";
		cout << "You hit for " << damage << " points of damage \n";
		health = health - damage;

	}
	else if (armor <= roll + atk){
		int damage = atk - def;
		cout << "You hit for " << damage << " points of damage \n";
		health = health - damage;

	}
	else if (armor> roll + atk){
		cout << "You miss." << endl;
	}
	return health; //returns the health of mob after attack
}
