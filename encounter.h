#ifndef ENCOUNTER_H
#define ENCOUNTER_H

//Basic struct of type stats used as the basis for 
//all monster and player stats
struct stats{
    int attack;
    int maxdefense;
    int defense;
    int hp;
    int maxhp;
    int armor;
    int mp;
    int maxmp;
    };

/**
 * Generates a random number between 1 - 3 to set what monster attacks the player
 * @param: There are no parameters taken in for this function
 * @return: monster stats in the form of a struct of type stats
 * */
 
stats encounter();

#endif
