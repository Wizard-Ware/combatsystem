#ifndef MAGIC_H
#define MAGIC_H

//Basic struct of type magic to be used for magic casting

class magic{
public:
	int fireball;
	int fireball_cost;
	int healing_touch;
	int healing_touch_cost;
	int ward;
	int ward_cost;
};

void fireball(int cost, int &MP, int firedamage, int &mobHealth, int mobarmor, int mobdef);

void healing(int cost, int &MP, int healing, int maxHP, int &HP);

void ward(int cost, int &MP, int amount, int maxDEF, int &def);

#endif
