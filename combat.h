#ifndef COMBAT_H
#define COMBAT_H

struct magic{
	int fireball;
	int fireball_cost;
	int healing_touch;
	int healing_touch_cost;
	int ward;
	int ward_cost;
};

int combat_system_mob(int atk, int armor, int health, int def, int maxhp);

int combat_system_player(int atk, int armor, int health, int def, int maxhp);

#endif
