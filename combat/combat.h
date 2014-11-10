#ifndef COMBAT_H
#define COMBAT_H


/**
 * Rolls a random number from 1 - 20 to check if the mob hits player and applies damaged based
 * on the stats of the mob. 
 * @param: attack of monster and armor health def and maxhp of player
 * @return: health of player
 * */
int combat_system_mob(int atk, int armor, int health, int def, int maxhp);

/**
 * Rolls a random number from 1 - 20 to check if player hits mob and applies damage based
 * on the stats of mob
 * @param: attack of player and armor, health, def, and maxhp of mob
 * @return: health of mob
 * */
int combat_system_player(int atk, int armor, int health, int def, int maxhp);

#endif
