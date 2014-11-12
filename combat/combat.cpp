#include <iostream>
#include <ctime>
#include <cstdlib>
using std::cout;
using std::endl;


int combat_system_mob(int atk, int armor, int health, int def, int maxhp){
	int roll, damage;
	srand(time(0) + 3);
	roll = (rand() % 20) + 1;
	if (roll == 20){
		int damage = (atk * 2) - def;
		cout << "The monster attacks and get a critital\n";
		cout << "It hits you for " << damage << " points of damage. \n";
		health = health - damage;

	}
	else if (armor <= roll + atk){
		int damage = atk - def;
		if(damage <= 0){
			cout << "The monster strikes, but the blow is deflected off your armor" << endl;
		}
		else if(damage > 0){
			cout << "The monster hits for " << damage << " points of damage. \n";
			health = health - damage;
		}
	}
	else if (armor> roll + atk){
		cout << "The monster misses you." << endl;
	}
	return health;
}

int combat_system_player(int atk, int armor, int health, int def, int maxhp){
	int roll, damage;
	srand(time(0));
	roll = (rand() % 20) + 1;
	if (roll == 20){
		int damage = (atk * 2) - def;
		cout << "You swing your sword and get a critital\n";
		cout << "You hit for " << damage << " points of damage \n";
		health = health - damage;

	}
	else if (armor <= roll + atk){
		int damage = atk - def;
		if(damage <= 0){
			cout << "Your blade hits, but if harmlessly deflected away." << endl;
		}
		elseif(damage > 0){
			cout << "You hit for " << damage << " points of damage \n";
			health = health - damage;
		}

	}
	else if (armor> roll + atk){
		cout << "You miss." << endl;
	}
	return health;
}
